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
        stack<ListNode*> st;

        ListNode* p = head;
        int count = 0;
        while (p != nullptr) {
            count++;
            st.push(p);
            p=p->next;
        }
        ListNode *temp = nullptr, *newHead, *q = head ;
        int flag = 0, i = 0;
        while (i < count) {
            if (flag == 0) {
                if (temp != nullptr) {
                    q->next = temp;
                    q = temp;

                } else {
                    newHead = q = head;
                }
                temp = q->next;
                q->next = nullptr;
                flag = 1;
            } else {
                q->next = st.top();
                st.pop();
                q = q->next;
                q->next = nullptr;
                flag = 0;
            }
            i++;
        }

        head=newHead;
    }
};
