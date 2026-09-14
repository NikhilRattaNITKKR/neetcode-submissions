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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* r = nullptr;
        ListNode* head = nullptr;
        ListNode* p = list1;
        ListNode* q = list2;

        while (p != nullptr && q != nullptr) {
            if (p->val < q->val) {
                if (r == nullptr) {
                    head = r = p;
                } else {
                    r->next = p;
                    r = r->next;
                }
                p = p->next;
            } else {
                if (r == nullptr) {
                    head = r = q;
                } else {
                    r->next = q;
                    r = r->next;
                }
                q = q->next;
            }
        }

        while (p != nullptr) {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        while (q != nullptr) {
            r->next = q;
            r = r->next;
            q = q->next;
        }

        return head;
    }
};
