/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (42.18%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.9M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 * 
 * 
 */
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
  int size = nums.size(), lindex = 0, rindex = size-1;
  int mid;
  if (size == 1) { return nums[0]==target?0:(nums[0]<target?1:0);}
  while (lindex <= rindex) {
    mid = (rindex+lindex)/2;
    if (nums[mid] == target) return mid;
    if (nums[mid] > target) {
      if ( mid-1 >= lindex) 
	rindex = mid-1;
      else 
	break;
    }
    else {
      if (mid+1 <= rindex) 
	lindex = mid+1;
      else 
	break;
    }
  }
  if (nums[mid] > target) return mid;
  else return (mid+1);
  }
};
