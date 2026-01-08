struct Node {
    int key;
    int val;
    struct Node* next;
    struct Node* prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {};
};

class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> table;

    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node(-1, 0);
        tail = new Node(-1, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (table.count(key) == 0) return -1;

        Node* node = table[key];
        cutLinks(node);
        markAsMostRecent(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (table.count(key)) {
            Node* node = table[key];
            node->val = value;
            cutLinks(node);
            markAsMostRecent(node);
        }
        else {
            if (table.size() == cap) {
                Node* lru = tail->prev;
                table.erase(lru->key);
                cutLinks(lru);
                delete lru;
            }
            Node* node = new Node(key, value);
            table[key] = node;
            markAsMostRecent(node);
        }
    }

private:
    void cutLinks(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void markAsMostRecent(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */