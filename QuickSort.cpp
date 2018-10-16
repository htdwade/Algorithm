#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//算法导论单向扫描
int partition1(vector<int>& nums, int left, int right){
    int x = nums[right];
    int i = left - 1;
    int j = left;
    while(j < right){
        if(nums[j] <= x)
            swap(nums[++i], nums[j]);
        j++;
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

//算法双向扫描
int partition2(vector<int>& nums, int left, int right){
    int i = left, j = right + 1;
    int pivot = nums[left];
    while(true){
        while(nums[++i] < pivot)
            if(i == right)
                break;
        while(nums[--j] > pivot)
            if(j == left)
                break;
        if(i >= j)
            break;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[j]);
    return j;
}

void quickSort(vector<int>& nums, int left, int right){
    if(left < right){
        int p = partition2(nums, left, right);
        quickSort(nums, left, p - 1);
        quickSort(nums, p + 1, right);
    }
}

int main()
{

    vector<int> nums;
    int x;
    while(cin >> x)
        nums.push_back(x);
    cout << "排序前:" << endl;
    for(auto a : nums)
        cout << a << '\t';
    quickSort(nums, 0, nums.size() - 1);
    cout << '\n' << "排序后:" << endl;
    for(auto a : nums)
        cout << a << '\t';
	return 0;
}
