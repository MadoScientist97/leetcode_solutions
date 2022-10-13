/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (51.01%)
 * Total Accepted:    531.4K
 * Total Submissions: 987.6K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 * 
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size()==0) return 0;
        if (triangle.size()==1) return triangle[0][0];
        vector<int> prevLevel(1,triangle[0][0]);
        int prevSize = prevLevel.size();
        for (int i=1;i<triangle.size();i++) {
            vector<int> currLevel(triangle[i].size(),INT_MAX);
            int currSize = currLevel.size()-1;
            for (int j=0;j<triangle[i].size();j++) {
                int choose = 0;
                if (j == 0) choose = prevLevel[0];
                else if (j==currSize) choose = prevLevel[j-1];
                else choose = min(prevLevel[j],prevLevel[j-1]);
                currLevel[j] = choose + triangle[i][j];
            }
            prevLevel = currLevel;
        }
        int minPath = INT_MAX;
        for (auto v:prevLevel) {
            if (v<minPath) minPath=v;
        }
        return minPath;
    }
};
