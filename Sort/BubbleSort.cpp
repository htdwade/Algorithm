#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& nums){
    if(nums.size() < 2)
        return;
    int n = nums.size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - i; j++)
            if(nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}

int main()
{

    vector<int> nums;
    int x;
    while(cin >> x)
        nums.push_back(x);
    cout << "排序前" << endl;
    for(auto a : nums)
        cout << a << '\t';
    bubbleSort(nums);
    cout << '\n' << "排序后" << endl;
    for(auto a : nums)
        cout << a << '\t';
	return 0;
}
