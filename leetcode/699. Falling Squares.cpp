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
            node->left->val = node->lazy;
            node->right->val = node->lazy;
            node->left->lazy = node->lazy;
            node->right->lazy = node->lazy;
            node->lazy = 0;
        }
    }

    void insert(SegmentNode* node, int start, int end, int left, int right, int val) {
        if (end < left || start > right) return;
        if (start >= left && end <= right) {
            node->val = val;
            node->lazy = val;
            return;
        }

        pushDown(node);

        int mid = start + (end - start) / 2;
        insert(node->left, start, mid, left, right, val);
        insert(node->right, mid + 1, end, left, right, val);

        node->val = max(node->left->val, node->right->val);
    }

    int query(SegmentNode* node, int start, int end, int left, int right) {
        if (end < left || start > right) return 0;
        if (start >= left && end <= right) return node->val;

        pushDown(node);

        int mid = start + (end - start) / 2;
        int leftMax = query(node->left, start, mid, left, right);
        int rightMax = query(node->right, mid + 1, end, left, right);

        return max(leftMax, rightMax);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        SegmentTree st;

        vector<int> result;
        for (auto& pos : positions) {
            int left = pos[0], right = pos[0] + pos[1] - 1;
            int h = pos[1];

            int maxH = st.query(st.root, 0, 1e9, left, right);
            st.insert(st.root, 0, 1e9, left, right, h + maxH);
            result.push_back(st.root->val);
        }

        return result;
    }
};