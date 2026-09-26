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
        ListNode *p = head, *q = head;
        int size = 0;
        while (p != nullptr) {
            size++;
            p = p->next;
        }
        int m = size - n + 1;
        q = p = head;

        if(m==1){
            head=head->next;
            return head;
        }
        while (m > 1) {
            m--;
            q = p;
            p = p->next;
        }
        q->next = p ? p->next : nullptr;
        if(p!=nullptr)
        p->next = nullptr;

        if (size == 1) return nullptr;

        return head;
    }
};
