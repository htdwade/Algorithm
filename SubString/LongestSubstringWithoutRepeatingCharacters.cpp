/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, 0);
        int start = 0, end = 0, len = 0;
        int count = 0;
        while(end < s.size()){
            if(hash[s[end++]]++ > 0)
                count++;
            while(count > 0){
                if(hash[s[start++]]-- > 1)
                    count--;
            }
            len = max(len, end - start);
        }
        return len;
    }
};

int main()
{
    Solution solution;
    string s1 = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s1) << endl;
    string s2 = "bbbbb";
    cout << solution.lengthOfLongestSubstring(s2) << endl;
    string s3 = "pwwkew";
    cout << solution.lengthOfLongestSubstring(s3) << endl;
    return 0;
}
