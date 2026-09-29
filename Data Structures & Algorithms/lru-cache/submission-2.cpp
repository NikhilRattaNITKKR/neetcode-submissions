struct ListNode {
    int val;
    int key;
    ListNode* prev;
    ListNode* next;

    ListNode(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
   public:
    unordered_map<int, ListNode*> hm;
    ListNode *head = nullptr, *tail = nullptr;
    int capacity;

    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (hm.count(key) == 0) return -1;

        ListNode* temp = hm[key];
        remove(temp);
        insertAtTail(temp);
        return temp->val;
    }

    void put(int key, int value) {
        ListNode* temp = nullptr;

        if (hm.count(key) == 0) {
            temp = new ListNode(key, value);
        } else {
            temp = hm[key];
            temp->val = value;
            remove(temp);
        }
        temp = insertAtTail(temp);
        hm[key] = temp;

        if (hm.size() > capacity) {
            hm.erase(head->key);
            remove(head);
        }
    }

   private:
    void remove(ListNode* temp) {
        if (head == tail && temp == head) {
            head = nullptr;
            tail = nullptr;
        } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        temp->next = nullptr;
        temp->prev = nullptr;
    }
    ListNode* insertAtTail(ListNode* temp) {
        if (head == nullptr) {
            head = tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = tail->next;
        }

        return temp;
    }
};
