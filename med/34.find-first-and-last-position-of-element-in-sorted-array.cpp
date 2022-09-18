/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (41.17%)
 * Total Accepted:    1.3M
 * Total Submissions: 3.2M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */
class Solution {
public:
    int search (vector<int>&nums, int target, bool forleft){
        int lp = 0, rp = nums.size()-1;
        while (lp<rp) {
            int mid = (lp+rp)/2;
            if (nums[mid] > target || (forleft && nums[mid]==target)) 
                rp = mid;    
            else 
                lp = mid+1;
        }
    return lp;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size==0) return vector<int>({-1,-1});
        if (size==1) {if (nums[0]==target) return vector<int>({0,0}); else return vector<int>({-1,-1});}                 int lp = 0, rp = size-1,index1=-1,index2=-1;
        // Find left
        if (nums[0]!=target) 
            index1=search(nums,target,true);
        else 
            index1=0;
        // Find right
        if (nums[size-1]!=target) 
            index2=search(nums,target,false)-1;
        else 
            index2 = size-1;
        if (index1==size || nums[index1]!=target) return {-1,-1};
        return {index1,index2};
    }
};
