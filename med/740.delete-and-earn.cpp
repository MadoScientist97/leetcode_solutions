/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 *
 * https://leetcode.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (57.38%)
 * Total Accepted:    221.8K
 * Total Submissions: 386.1K
 * Testcase Example:  '[3,4,2]'
 *
 * You are given an integer array nums. You want to maximize the number of
 * points you get by performing the following operation any number of
 * times:
 * 
 * 
 * Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must
 * delete every element equal to nums[i] - 1 and every element equal to nums[i]
 * + 1.
 * 
 * 
 * Return the maximum number of points you can earn by applying the above
 * operation some number of times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,4,2]
 * Output: 6
 * Explanation: You can perform the following operations:
 * - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
 * - Delete 2 to earn 2 points. nums = [].
 * You earn a total of 6 points.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,2,3,3,3,4]
 * Output: 9
 * Explanation: You can perform the following operations:
 * - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums =
 * [3,3].
 * - Delete a 3 again to earn 3 points. nums = [3].
 * - Delete a 3 once more to earn 3 points. nums = [].
 * You earn a total of 9 points.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size()==1) return nums[0];
        map<int,int> fmap,cache;
        int maxnum=INT_MIN;
        if (nums.size()==2) {
            if (abs(nums[0]-nums[1])==1) 
                return max(nums[0],nums[1]); 
            else 
                return nums[0]+nums[1];
        }
        for (int i=0;i<nums.size();i++) {
            if (maxnum<nums[i]) maxnum = nums[i];
            if (fmap.find(nums[i])==fmap.end())
                fmap[nums[i]]=1;
            else
                fmap[nums[i]]++;
        }
        vector<int> maxval(maxnum+1,0);
        maxval[0] = 0;
        if (fmap.find(1)==fmap.end())
            maxval[1] = 0;
        else
            maxval[1] = fmap[1];
        for (int i=2;i<=maxnum;i++) {
            int freq;
            if (fmap.find(i)==fmap.end())
                freq = 0;
            else
                freq = fmap[i];
            maxval[i] = max(maxval[i-2]+i*freq,maxval[i-1]);
        }
        return *maxval.rbegin();
    }
};
