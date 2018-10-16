#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

//算法导论单向扫描
int partition1(vector<int>& nums, int left, int right) {
	swap(nums[left], nums[left + rand() % (right - left + 1)]);
	int v = nums[left];
	//nums[left+1...i] < v, nums[i+1...j) > v
	int i = left;
	int j = left + 1;
	while (j <= right) {
		if (nums[j] < v)
			swap(nums[++i], nums[j]);
		j++;
	}
	swap(nums[i], nums[left]);
	return i;
}

//算法双向扫描
int partition2(vector<int>& nums, int left, int right) {
	swap(nums[left], nums[left + rand() % (right - left + 1)]);
	int v = nums[left];
	//nums[left+1...i) <= v, nums(j...right] >= v
	int i = left + 1, j = right;
	while (true) {
		while (i <= right && nums[i] < v) i++;
		while (j >= left + 1 && nums[j] > v) j--;
		if (i > j)
			break;
		swap(nums[i++], nums[j--]);
	}
	swap(nums[left], nums[j]);
	return j;
}

void _quickSort(vector<int>& nums, int left, int right) {
	if (left >= right)
		return;
	int p = partition2(nums, left, right);
	_quickSort(nums, left, p - 1);
	_quickSort(nums, p + 1, right);
}

//三路快排
void _quickSort3Ways(vector<int>& nums, int left, int right) {
	if (left >= right)
		return;
	swap(nums[left], nums[left + rand() % (right - left + 1)]);
	int v = nums[left];
	int lt = left;//nums[left+1...lt] < v
	int gt = right + 1;//nums[gt...right] > v
	int i = left + 1; //nums[lt+1...i) == v
	while (i < gt) {
		if (nums[i] < v)
			swap(nums[i++], nums[++lt]);
		else if (nums[i] > v)
			swap(nums[i], nums[--gt]);
		else
			++i;
	}
	swap(nums[left], nums[lt]);
	_quickSort3Ways(nums, left, lt - 1);
	_quickSort3Ways(nums, gt, right);
}

void quickSort(vector<int>& nums) {
	srand(time(NULL));
	//_quickSort(nums, 0, nums.size() - 1);
	_quickSort3Ways(nums, 0, nums.size() - 1);
}

int main()
{

	vector<int> nums;
	int x;
	while (cin >> x)
		nums.push_back(x);
	cout << "排序前" << endl;
	for (auto a : nums)
		cout << a << '\t';
	quickSort(nums);
	cout << '\n' << "排序后" << endl;
	for (auto a : nums)
		cout << a << '\t';
	return 0;
}
