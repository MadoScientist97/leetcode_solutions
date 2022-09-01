/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (51.78%)
 * Total Accepted:    469.1K
 * Total Submissions: 897.8K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 * 
 * 
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 * 
 * 
 */
class Solution {
public:
    bool check(vector<vector<int>>&grid, int r, int c) {
        return (r >=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]==1);
    }
    bool flag=false;
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size()==0) return 0;
        if (grid.size()==1 && grid[0].size()==1) return grid[0][0]==1?(-1):0;
        int deltaT = 0;
        set<pair<int,int>> current, looknext;
        for (int i=0;i < grid.size();i++) {
            for (int j=0;j < grid[i].size();j++) {
                if (grid[i][j]== 2) looknext.insert(pair(i,j));
            }
        }
        while (!looknext.empty()) {
            flag = true;
            current = looknext;
            looknext.clear();
            for (auto p:current) {
                if (check(grid,p.first-1,p.second)) {  
                    looknext.emplace(pair(p.first-1,p.second));
                    grid[p.first-1][p.second] = 2;
                }
                if (check(grid,p.first+1,p.second)) {
                    looknext.emplace(pair(p.first+1,p.second));
                    grid[p.first+1][p.second] = 2;
                }
                if (check(grid,p.first,p.second-1)) {
                    looknext.emplace(pair(p.first,p.second-1));
                    grid[p.first][p.second-1] = 2;
                }
                if (check(grid,p.first,p.second+1)) {
                    looknext.emplace(pair(p.first,p.second+1));
                    grid[p.first][p.second+1] = 2;
                }
            }
            deltaT++;
        
        }
        for (int i=0;i < grid.size();i++) {
            for (int j=0;j < grid[i].size();j++) {
                if (grid[i][j]== 1) return -1;
            }
        }
        return flag?deltaT-1:deltaT;    
    }
};
