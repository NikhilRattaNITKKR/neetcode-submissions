/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        // handle n=0
        int n = 0;

        unordered_map<Node*, Node*> nodes;
        while (p != nullptr) {
            Node* temp = new Node(p->val);
            nodes[p] = temp;
            p = p->next;
            n++;
        }
        if (n == 0) {
            return head;
        }

        p = head;

        while (p != nullptr) {
            Node* next = nodes[p->next];
            Node* random = nodes[p->random];
            Node* currNode = nodes[p];
            currNode->random = random;
            currNode->next = next;
            p = p->next;
        }

        return nodes[head];
    }
};
