#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heap_size;

inline int left(int i){
    return (i << 1) + 1;
}

inline int right(int i){
    return (i << 1) + 2;
}

void max_heapify(vector<int>& nums, int i){
    int largest = i;
    int l = left(i), r = right(i);
    if(l < heap_size && nums[l] > nums[largest])
        largest = l;
    if(r < heap_size && nums[r] > nums[largest])
        largest = r;
    if(largest != i){
        swap(nums[largest], nums[i]);
        max_heapify(nums, largest);
    }
}

void build_max_heap(vector<int>& nums){
    heap_size = nums.size();
    for(int i = (heap_size << 1) - 1; i >= 0; i--)
        max_heapify(nums, i);
}

void heapSort(vector<int>& nums){
    build_max_heap(nums);
    for(int i = nums.size() - 1; i > 0; i--){
        swap(nums[i], nums[0]);
        heap_size--;
        max_heapify(nums, 0);
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
    heapSort(nums);
    cout << '\n' << "排序后:" << endl;
    for(auto a : nums)
        cout << a << '\t';
	return 0;
}
