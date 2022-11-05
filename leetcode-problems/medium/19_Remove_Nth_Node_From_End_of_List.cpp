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
        ListNode* tmp = head;
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        if (count == n) return tmp->next;
        int at = 0;
        head = tmp;
        while (head != NULL) {
            at++;
            if (at == count - n) {
                head->next = head->next->next;
                break;
            }
            head = head->next;
        }
        return tmp;
    }
};