/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (37.89%)
 * Total Accepted:    1.7M
 * Total Submissions: 4.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 * 
 * Prior to being passed to your function, nums is possibly rotated at an
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
 * and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is an ascending array that is possibly rotated.
 * -10^4 <= target <= 10^4
 * 
 * 
 */
class Solution {
public:
    int getStart (vector<int>& nums) {
        int lp = 0, rp = nums.size()-1;
        while (lp<rp-1) {
            int mid = (lp+rp)/2;
            if (nums[mid] < nums[lp])
                rp  = mid;
            else
                lp = mid;
        }
        if (lp && nums[lp] < nums[lp-1]) return lp;
        else return lp + 1;
    }
    int searchb(vector<int>& nums, int target, int sp) {
        int res = -1;
        int size = nums.size()-1;
        int lp = sp%size, rp = sp+size;
        while (lp < rp) {
            int mid = (lp+rp)/2;
            if (nums[mid%(size+1)] == target) {res = mid%(size+1); break;}
            else if (target < nums[mid%(size+1)]) rp = mid;
            else lp = mid+1;
        }
        if (nums[lp%(size+1)] == target) res = lp%(size+1);
        return res;
    }
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size==0) return -1;
        if (size==1) {if (nums[0] == target) return 0; else return -1;}
        int start = getStart(nums);
        return searchb(nums,target,start);
    }
};
