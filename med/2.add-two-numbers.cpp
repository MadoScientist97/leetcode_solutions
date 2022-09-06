/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (38.73%)
 * Total Accepted:    3.1M
 * Total Submissions: 7.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultList=nullptr;
        ListNode* iterList=nullptr;
        int nextadd=0;
        int carry=0;
        while (l1!=nullptr && l2!=nullptr) {
            nextadd = l1->val + l2->val + carry;
            carry = 0;
            if (nextadd>9)  { carry = nextadd/10l; nextadd = nextadd%10; }
            if(!resultList) {resultList = new ListNode(nextadd); iterList = resultList;} 
            else { iterList->next = new ListNode(nextadd);  iterList = iterList->next; }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remaining=nullptr;
        if (l1)
            remaining = l1;
        else
            remaining = l2;
        
        while (remaining!=nullptr) {
            nextadd = remaining->val + carry;
            carry = 0;
            if (nextadd>9) { 
                carry = nextadd/10; 
                nextadd = nextadd%10;
            }
            iterList->next = new ListNode(nextadd);
            iterList = iterList->next;
            remaining = remaining->next;
        }
        if (carry) iterList->next = new ListNode(carry);
    return resultList;
    }
};
