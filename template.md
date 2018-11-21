# 算法模板

## 1.子串问题

对于大多数子串问题，给定一个字符串，然后需要找到一个满足某些限制条件的子串，一个通用的方法是使用hash表+双指针的策略，通用模板如下：
```cpp
int findSubstring(string s){
        vector<int> hash(256, 0);
        int count; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int len; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end < s.size()){

            if(map[s[end++]]-- ?){  /* modify count here */ }

            while(/* count condition */){ 
                 
                 /* update len here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify count here*/ }
            }  

            /* update len here if finding maximum*/
        }
        return len;
  }
```
需要注意的是，当查找最大子串时，应该在确保子串合法的while循环结束后更新最大值，当查找最小子串时，应该在while循环里面更新最小值。

## 2. 求两个有序数组中第k小的数

对于两个有序数组 a[1…m],  b[1…n]，求两个数组合一起后第 k 小的数，假设 m < n，在数组 a 中找到第 k / 2 小的数 ai，在数组 b 中找到第 k - i 小的数 bj（不说 k / 2 是为了避免 k 的奇偶造成的 i + j 不一定等于 k 的情况），i + j = k。（注意 k / 2 可能大于 m，若大于 m，则用 am 代替 ai，此时 j = k - m) 

i 和 j 将数组a，b分别划分为两部分，比较 ai 和 bj 的大小： 

* 若ai > bj，说明第 k 小的数不可能出现在数组 a 的右部，也不可能出现在数组 b 的左部（用反证法可证），舍弃这部分，在 a 的左部(包含 ai)和 b 的右部(不包含 bj)中查找第 k - j 小的数。(因为此时 b[1...j] 必然在前 k 个数中) 
* 若ai < bj，说明第 k 小的数不可能出现在数组 a 的左部，也不可能出现在数组 b 的右部（用反证法可证），舍弃这部分，在 a 的右部(不包含 ai)和 b 的左部(包含 bj)中查找第 k - i 小的数。(因为此时 a[1...i] 必然在前 k 个数中) 
* 若ai = bj，说明第 k 小的数就是 ai，可并入上述两种情况之一。

```cpp
//l1，l2为搜索区间左边界，m，n为搜索区间大小
int findKthNum(vector<int>& nums1, int l1, int m, vector<int>& nums2, int l2, int n, int k){
        if(m > n)
            return findKthNum(nums2, l2, n, nums1, l1, m, k);
        if(m == 0)
            return nums2[l2 + k - 1];
        if(k == 1)
            return min(nums1[l1], nums2[l2]);
        int i = min(m, k / 2);
        int j = k - i;
        if(nums1[l1 + i - 1] == nums2[l2 + j - 1])
            return nums1[l1 + i - 1];
        else if(nums1[l1 + i - 1] > nums2[l2 + j - 1])
            return findKthNum(nums1, l1, i, nums2, l2 + j, n - j, k - j);
        else
            return findKthNum(nums1, l1 + i, m - i, nums2, l2, j, k - i);
    }
```