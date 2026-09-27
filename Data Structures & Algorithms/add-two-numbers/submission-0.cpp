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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1,*q=l2,*first=l1,*r=l1,*last=nullptr;
        int carry=0;

        while(p!=nullptr && q!=nullptr){
        p=p->next;
        q=q->next;
        }
        if(q){
            first=r=l2;
        }
        p=l1;
        q=l2;
        
        while(p!=nullptr || q!=nullptr){
            int val1=p? p->val : 0;
            int val2=q? q->val : 0;
            int value=(val1+val2+carry);
            carry=value/10;
            value=value%10;
            
            r->val=value;
            if(r->next==nullptr){
                last=r;
            }
            r=r->next;
            if(p!=nullptr)p=p->next;            
            if(q!=nullptr)q=q->next;
        }
        if(carry){
            last->next=new ListNode(carry);
        }

        return first;
    }
};
