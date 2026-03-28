struct SegmentNode {
    int val;
    int lazy;
    SegmentNode* left;
    SegmentNode* right;

    SegmentNode() : val(0), lazy(0), left(nullptr), right(nullptr) {}
};

class SegmentTree {
public:
    SegmentNode* root;

    SegmentTree() {
        this->root = new SegmentNode();
    }

    void pushDown(SegmentNode* node) {
        if (node->left == nullptr) node->left = new SegmentNode();
        if (node->right == nullptr) node->right = new SegmentNode();

        if (node->lazy > 0) {
            node->left->val += node->lazy;
            node->left->lazy += node->lazy;
            node->right->val += node->lazy;
            node->right->lazy += node->lazy;
            node->lazy = 0;
        }
    }

    void update(SegmentNode* node, int start, int end, int left, int right, int val) {
        if (end < left || start > right) return;
        if (start >= left && end <= right) {
            node->val += val;
            node->lazy += val;
            return;
        }

        pushDown(node);

        int mid = start + (end - start) / 2;
        update(node->left, start, mid, left, right, val);
        update(node->right, mid + 1, end, left, right, val);

        node->val = max(node->left->val, node->right->val);
    }
};

class MyCalendarThree {
    SegmentTree st;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        st.update(st.root, 0, 1e9, startTime, endTime - 1, 1);
        return st.root->val;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */