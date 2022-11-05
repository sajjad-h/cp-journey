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
    
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* head = new ListNode();
        ListNode* ans = head;
        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                head->next = head1;
                head1 = head1->next;
                head = head->next;
            }
            else {
                head->next = head2;
                head2 = head2->next;
                head = head->next;
            }
        }
        while (head1 != NULL) {
            head->next = head1;
            head1 = head1->next;
            head = head->next;
        }
        while (head2 != NULL) {
            head->next = head2;
            head2 = head2->next;
            head = head->next;
        }
        head->next = NULL;
        return ans->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return NULL;
        int p = 1;
        while (p < k) {
            int i = 0;
            while (i + p < k) {
                lists[i] = merge2Lists(lists[i], lists[i + p]);
                i = i + 2*p;
            }
            p = 2*p;
        }
        return lists[0];
    }
};