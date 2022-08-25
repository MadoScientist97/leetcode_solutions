/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.21%)
 * Total Accepted:    2.2M
 * Total Submissions: 6.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size()<3) return {};
        map<int,int> dat;
        unordered_set<int> multi;
        int target = 0;
        set<vector<int>> triplets;
        for (int i = 0; i<nums.size();i++) {
            dat[nums[i]] = i;
        }
        for (int i = 0; i < nums.size()-2; i++){
        if (multi.insert(nums[i]).second)    
            for (int j = i+1; j<nums.size(); j++) {
            vector<int> idx;
            int fval = target - (nums[j]+nums[i]);
            if (dat.find(fval)!=dat.end() && dat[fval]>j) {
                idx.push_back(nums[j]); idx.push_back(nums[dat[fval]]);
                idx.push_back(nums[i]);
                sort(idx.begin(),idx.end());
                triplets.insert(idx);
                }
            }
        }
        return {triplets.begin(),triplets.end()};
    }
};
