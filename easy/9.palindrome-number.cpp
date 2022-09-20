/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (52.45%)
 * Total Accepted:    2.5M
 * Total Submissions: 4.7M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is palindrome integer.
 * 
 * An integer is a palindrome when it reads the same backward as forward.
 * 
 * 
 * For example, 121 is a palindrome while 123 is not.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without converting the integer to a string?
 */
class Solution {
public:
    int reverse(int x) {
        int revint=x%10,count = 1;
        x= x/10;
        while (x && count<9) {
            revint = revint*10 + x%10;
            x=x/10;
            count++;
        }
    if (x/10!=0) {
        return 0;
    }
    if (x>0) {
        if ( (revint > INT_MAX/10) || ((revint == INT_MAX/10) && (x%10) > 7)) return 0;
        else revint = revint*10 + (x%10);
    }
    if (x<0) {
        if ( (revint < INT_MIN/10) || ((revint == INT_MIN/10) && (x%10) < -8)) return 0;
        else revint = revint*10 + (x%10);
    }
    return revint;
    }
    
    
    bool isPalindrome(int x) {
        if (x<0) return false;
        int32_t revInt;
        revInt = reverse(x);
        if (revInt == x) return true;
        else return false;
    }
};
