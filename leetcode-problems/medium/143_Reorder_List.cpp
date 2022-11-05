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
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode* tmp = head;
        while (head != NULL) {
            list.push_back(head);
            head = head->next;
        }
        int i = 1, j = list.size() - 1;
        int k = 1;
        head = tmp;
        while (i <= j) {
            if (k % 2 == 1) {
                head->next = list[j--];
                head = head->next;
            }
            else {
                head->next = list[i++];
                head = head->next;
            }
            k++;
        }
        head->next = NULL;
    }
};