struct Node {
    int key;
    int val;
    struct Node* next;

    Node (int k, int v, Node* n) : key(k), val(v), next(n) {}

};

class MyHashMap {
public:
    int capacity = 1000;
    vector<Node*> table;

    MyHashMap() {
        table.resize(capacity, nullptr);
    }

    ~MyHashMap() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i] != nullptr) {
                Node* head = table[i];
                while (head) {
                    Node* tmp = head;
                    head = head->next;
                    delete tmp;
                }
            }
        }
    }

    int hash(int key) {
        return key % capacity;
    }
    
    void put(int key, int value) {
        int k = hash(key);
        Node* head = table[k];

        // Override
        Node* curr = head;
        while (curr) {
            if (curr->key == key) {
                curr->val = value;
                return;
            }
            curr = curr->next;
        }

        Node* node = new Node(key, value, head);
        table[k] = node;
    }
    
    int get(int key) {
        Node* head = table[hash(key)];
        Node* curr = head;
        while (curr) {
            if (curr->key == key) return curr->val;
            curr = curr->next;
        }

        return -1;
    }
    
    void remove(int key) {
        int k = hash(key);
        Node* head = table[k];
        if (head == nullptr) return;

        if (head->key == key) {
            Node* tmp = head;
            head = head->next;
            table[k] = head;
            delete tmp;
            return;
        }

        Node* curr = head;
        while (curr->next) {
            if (curr->next->key == key) {
                Node* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */