/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (44.46%)
 * Total Accepted:    549.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *first=head, *second=head;
        if (!head || head->next==nullptr) {
            return head;
        }
        second = second->next;
        if (second->next==nullptr) {
            if (first->val == second->val) {
                delete second; delete first; return nullptr;
            }
            else return head;
        }
        ListNode *sentinel = new ListNode(-1000,first);
        first=sentinel;
        head = sentinel;
        while (second) {
            if (second->val == first->next->val) {
                while (second && second->val == first->next->val) {
                    second = second->next;
                    delete first->next->next;
                    first->next->next = second;
                }
                delete first->next;
                first->next = second;
                if (second)
                    second = second->next;
                else break;
            }
            else {
                first = first->next;
                second = second->next;
            }
        }
        ListNode *res = head->next;
        delete head;
        return res;
    }
};
