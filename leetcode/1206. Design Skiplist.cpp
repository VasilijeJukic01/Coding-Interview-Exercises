class Node {
public:
    int val;
    Node** forward;

    Node(int val, int level) {
        this->val = val;
        this->forward = new Node*[level + 1];
        memset(this->forward, 0, sizeof(Node*) * (level + 1));
    }

    ~Node() {
        delete[] forward;
    }
};

class Skiplist {
    Node* head;
    int level;
    int maxLevel;
    double prob;
public:
    Skiplist() {
        this->maxLevel = 16;
        this->prob = 0.5;
        this->head = new Node(-1, maxLevel);
        this->level = 0;
    }

    int getRandomLevel() {
        int lvl = 0;
        double p = (double) rand() / (double) RAND_MAX;
        while (p < prob && lvl < maxLevel) {
            p = (double) rand() / (double) RAND_MAX;
            lvl++;
        }
        return lvl;
    }
    
    bool search(int target) {
        Node* curr = head;
        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        if (curr && curr->val == target) return true;
        return false;
    }
    
    void add(int num) {
        // Need for links
        Node* update[maxLevel + 1];
        memset(update, 0, sizeof(Node*) * (maxLevel + 1));

        Node* curr = head;
        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        curr = curr->forward[0];

        int lvl = getRandomLevel();

        if (lvl > level) {
            for (int i = level + 1; i < lvl + 1; i++) {
                update[i] = head;
            }
            level = lvl;
        }

        Node* node = new Node(num, lvl);
        for (int i = lvl; i >= 0; i--) {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
    }
    
    bool erase(int num) {
        // Need for links
        Node* update[maxLevel + 1];
        memset(update, 0, sizeof(Node*) * (maxLevel + 1));

        Node* curr = head;
        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        curr = curr->forward[0];

        if (curr == nullptr || curr->val != num) return false;
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != curr) break;
            update[i]->forward[i] = curr->forward[i];
        }
        
        delete curr;
        while (level > 0 && head->forward[level] == nullptr) {
            level--;
        }

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */