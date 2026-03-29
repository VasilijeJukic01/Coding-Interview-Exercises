struct SegmentNode {
    int val;
    int lazy;
    SegmentNode* left;
    SegmentNode* right;

    void init() {
        val = 0;
        lazy = -1;
        left = nullptr;
        right = nullptr;
    }
};

const int N = 1e6;
int ptr = 0;
SegmentNode pool[N];

SegmentNode* newNode() {
    pool[ptr].init();
    return &pool[ptr++];
}

class SegmentTree {
public:
    SegmentNode* root;

    SegmentTree() {
        ptr = 0;
        this->root = newNode();
    }

    void pushDown(SegmentNode* node) {
        if (node->left == nullptr) node->left = newNode();
        if (node->right == nullptr) node->right = newNode();
        if (node->lazy != -1) {
            node->left->val = node->lazy;
            node->right->val = node->lazy;
            node->left->lazy = node->lazy;
            node->right->lazy = node->lazy;
            node->lazy = -1;
        }
    }

    void insertUpdate(SegmentNode* node, int start, int end, int left, int right, int val) {
        if (end < left || start > right) return;
        if (start >= left && end <= right) {
            node->val = val;
            node->lazy = val;
            return;
        }

        pushDown(node);

        int mid = start + (end - start) / 2;
        insertUpdate(node->left, start, mid, left, right, val);
        insertUpdate(node->right, mid + 1, end, left, right, val);

        node->val = node->left->val && node->right->val;
    }

    bool query(SegmentNode* node, int start, int end, int left, int right) {
        if (end < left || start > right) return 1;
        if (start >= left && end <= right) return node->val;

        pushDown(node);

        int mid = start + (end - start) / 2;
        int leftState = query(node->left, start, mid, left, right);
        int rightState = query(node->right, mid + 1, end, left, right);

        return leftState && rightState;
    }
};

class RangeModule {
    SegmentTree st;
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        st.insertUpdate(st.root, 0, 1e9, left, right - 1, 1);
    }
    
    bool queryRange(int left, int right) {
        return st.query(st.root, 0, 1e9, left, right - 1);
    }
    
    void removeRange(int left, int right) {
        st.insertUpdate(st.root, 0, 1e9, left, right - 1, 0);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */