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

