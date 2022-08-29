/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.12%)
 * Total Accepted:    3.8M
 * Total Submissions: 11.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> currSub;
        int size = s.size();
        if (size==1) return 1;
        int count=0, lastmax=0,maxl=0;
        for (int iter = 0;iter<size;iter++) {
            if (currSub.empty() || currSub.find(s[iter])==currSub.end() || currSub[s[iter]] < maxl) {
                currSub[s[iter]] = iter;
                count++;
            }
            else {
                maxl = currSub[s[iter]]+1;
                if (count>lastmax) {
                    lastmax = count;
                }
                count = iter - maxl + 1;
                currSub[s[iter]]=iter;
            }
        }
        if (lastmax<count) lastmax = count; 
        return lastmax;
    }
};
