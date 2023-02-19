/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 *
 * https://leetcode.com/problems/count-number-of-teams/description/
 *
 * algorithms
 * Medium (69.31%)
 * Total Accepted:    98.9K
 * Total Submissions: 146.5K
 * Testcase Example:  '[2,5,3,4,1]'
 *
 * There are n soldiers standing in a line. Each soldier is assigned a unique
 * rating value.
 * 
 * You have to form a team of 3 soldiers amongst them under the following
 * rules:
 * 
 * 
 * Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j],
 * rating[k]).
 * A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] >
 * rating[j] > rating[k]) where (0 <= i < j < k < n).
 * 
 * 
 * Return the number of teams you can form given the conditions. (soldiers can
 * be part of multiple teams).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: rating = [2,5,3,4,1]
 * Output: 3
 * Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1),
 * (5,3,1). 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rating = [2,1,3]
 * Output: 0
 * Explanation: We can't form any team given the conditions.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: rating = [1,2,3,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == rating.length
 * 3 <= n <= 1000
 * 1 <= rating[i] <= 10^5
 * All the integers in rating are unique.
 * 
 * 
 */
class Solution {
public:
    int numTeams(vector<int>& rating) {
       int ratingListSize = rating.size();
       if (ratingListSize < 3) return 0;
       int TeamCountTotal = 0;
       for (int j = 0; j < ratingListSize; j++) {
           int leftLessThanJCount = 0;
           int leftMoreThanJCount = 0;
           int rightLessThanJCount = 0;
           int rightMoreThanJCount = 0;
           for (int i = 0; i < j; i++) {
               if (rating[i] > rating[j])
                   leftMoreThanJCount++;
               else if (rating[i] < rating[j])
                   leftLessThanJCount++;
           }
           for (int i = j+1; i < ratingListSize; i++) {
               if (rating[i] > rating[j])
                   rightMoreThanJCount++;
               else if (rating[i] < rating[j])
                   rightLessThanJCount++;
           }
       TeamCountTotal += (leftLessThanJCount * rightMoreThanJCount) + (leftMoreThanJCount*rightLessThanJCount);
       }
    return TeamCountTotal;
    }
};
