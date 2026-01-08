struct Node {
    int key;
    int val;
    int freq;
    struct Node* next;
    struct Node* prev;

    Node(int k, int v) : key(k), val(v), freq(1), next(nullptr), prev(nullptr) {} 
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = new Node(-1, 0);
        tail = new Node(-1, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~List() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void cutLinks(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->prev = head;
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
    }

    bool empty() {
        return head->next == tail;
    }

    int remove() {
        Node* node = tail->prev;
        int key = node->key;
        cutLinks(node);
        delete node;

        return key;
    }
};

class LFUCache {
public:
    int cap;
    int minFreq = 0;
    unordered_map<int, Node*> lookUpTable;
    unordered_map<int, List*> freqTable;

    LFUCache(int capacity) {
        this->cap = capacity;
    }

    void moveToUpperLevel(Node* node, List* list) {
        list->cutLinks(node);
        if (minFreq == node->freq && list->empty()) {
            minFreq++;
        }
        node->freq += 1;

        if (freqTable.count(node->freq) == 0) {
            freqTable[node->freq] = new List();
        }
        freqTable[node->freq]->addToHead(node);
    }
    
    int get(int key) {
        if (lookUpTable.count(key) == 0) return -1;

        Node* node = lookUpTable[key];
        List* list = freqTable[node->freq];
        moveToUpperLevel(node, list);

        return node->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        // If present
        if (lookUpTable.count(key)) {
            Node* node = lookUpTable[key];
            List* list = freqTable[node->freq];
            node->val = value;

            moveToUpperLevel(node, list);
        }
        // If not present
        else {
            Node* node = new Node(key, value);
            // If reached capacity
            if (lookUpTable.size() >= cap) {
                List* minFreqList = freqTable[minFreq];
                int deleteKey = minFreqList->remove();
                lookUpTable.erase(deleteKey);
            }

            if (freqTable.count(node->freq) == 0) {
                freqTable[node->freq] = new List();
            }
            freqTable[node->freq]->addToHead(node);
            
            lookUpTable[key] = node;
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */