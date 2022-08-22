/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (43.82%)
 * Total Accepted:    291.2K
 * Total Submissions: 662.1K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 * 
 * 
 */
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    if (mat.size()==0 || (mat.size()== 1 && mat[0].size()==1)) return mat;
    int row = mat.size(),col = mat[0].size();
    vector<vector<int>> dist(row, vector<int>(col,INT_MAX));
    // first iteration;
    for (int i=0;i<row;i++)
      for (int j=0;j<col;j++) {
        if (mat[i][j] == 0) dist[i][j] = 0;
        else dist[i][j] = min(i>0?(dist[i-1][j]==INT_MAX?INT_MAX:dist[i-1][j]+1):INT_MAX,j>0?(dist[i][j-1]==INT_MAX?INT_MAX:dist[i][j-1]+1):INT_MAX);
      }
    //second interation
    for (int i=row-1;i>=0;i--) 
      for (int j=col-1;j>=0;j--) {
        if (mat[i][j]!=0) {
          int rbmin = min((i<row-1)?(dist[i+1][j]==INT_MAX?INT_MAX:dist[i+1][j]+1):INT_MAX,(j<col-1)?(dist[i][j+1]==INT_MAX?INT_MAX:dist[i][j+1]+1):INT_MAX);
          dist[i][j]= min (dist[i][j],rbmin);
        }
      }
  return dist;
  }
};
