/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.84%)
 * Total Accepted:    2.5M
 * Total Submissions: 6.2M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2!=0) return false;
        stack<char> seen;
        seen.push(s[0]);
        for (int i=1;i<s.length();i++) {
            if (s[i] == '(' || s[i]=='{' || s[i]=='[')
                seen.push(s[i]);
            else if (s[i]==')') {
              if (seen.top()=='(') 
                seen.pop();
              else
                return false;
            }
            else if (s[i]=='}') {
              if (seen.top()=='{') 
                seen.pop();
              else
                return false;
            }
            else if (s[i]==']') {
              if (seen.top()=='[') 
                seen.pop();
              else
                return false;
            } 
        if (seen.empty()) return true;
        else return false;
    }
  }
};
