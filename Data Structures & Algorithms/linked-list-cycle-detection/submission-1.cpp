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
    bool hasCycle(ListNode* head) {
        if(head==nullptr)return false;
        if(head->next==nullptr)return false;
        ListNode* p=head;
        ListNode* q=head->next;
        
        while(p!=nullptr && q!=nullptr && p!=q){
            p=p->next;
            q=q->next;
            q= q ? q->next :nullptr;
            
        }

        if(p==q && p!=nullptr){
            return true;
        }

        return false;
    }
};
