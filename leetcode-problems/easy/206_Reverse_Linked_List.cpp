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
    
    ListNode* reverseListRecur(ListNode* head, ListNode* newHead) {
        if (head == NULL) return newHead;
        ListNode* next = head->next;
        head->next = newHead;
        return reverseListRecur(next, head);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseListRecur(head, NULL);
    }
};