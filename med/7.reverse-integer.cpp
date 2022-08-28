/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (26.75%)
 * Total Accepted:    2.2M
 * Total Submissions: 8.2M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 120
 * Output: 21
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
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
};
