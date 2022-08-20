/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (38.89%)
 * Total Accepted:    1.6M
 * Total Submissions: 4.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        if (head->next == nullptr && n==1) {
            delete head; head = nullptr; return head;
        } 
        ListNode *lahead = head, *lookn = head, *prev2n = head;
        for (int i=0;i<n;i++) {
                lahead = lahead->next;
        }
        if (lahead) {
            lahead=lahead->next;
            lookn = lookn->next;
        }
        if (lahead)
        while (lahead!=nullptr) {
            lahead=lahead->next;
            lookn=lookn->next;
            prev2n=prev2n->next;
        }
        if (prev2n==lookn) {
            head = head->next;
            delete prev2n;
            return head;
        }

        prev2n->next = prev2n->next->next;
        delete lookn;
        return head;
    }
};
