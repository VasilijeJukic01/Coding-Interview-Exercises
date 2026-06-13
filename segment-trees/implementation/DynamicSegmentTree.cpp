/*
 * Dynamic Lazy Segment Tree Implementation
 *
 * Logic:
 * - Uses explicit Node pointers (left, right) instead of an array.
 * - Supports Range Updates and Range Queries over extremely large bounds ([0, 10^9]).
 * - Children are created dynamically only when accessed or when lazy values need to be pushed down.
 *
 * Time Complexity:
 * - Range Update: O(log(MAX_RANGE))
 * - Range Query: O(log(MAX_RANGE))
 * Space Complexity: O(U * log(MAX_RANGE)) where U is the number of range updates.
 */

#include <iostream>

using namespace std;

struct SegmentNode {
    long long val;
    long long lazy;
    SegmentNode* left;
    SegmentNode* right;

    SegmentNode() : val(0), lazy(0), left(nullptr), right(nullptr) {}
};

class DynamicLazySegmentTree {
private:
    SegmentNode* root;
    long long minRange;
    long long maxRange;

    void pushDown(SegmentNode* node, long long start, long long end) {
        if (!node || node->lazy == 0) return;

        node->val += (end - start + 1) * node->lazy;

        // If not a leaf, propagate the lazy value downwards
        if (start != end) {
            if (!node->left) node->left = new SegmentNode();
            if (!node->right) node->right = new SegmentNode();
            node->left->lazy += node->lazy;
            node->right->lazy += node->lazy;
        }

        node->lazy = 0;
    }

    void updateRange(SegmentNode* node, long long start, long long end, long long l, long long r, long long val) {
        pushDown(node, start, end);

        if (end < l || start > r) return;
        if (start >= l && end <= r) {
            node->lazy += val;
            pushDown(node, start, end);
            return;
        }

        long long mid = start + (end - start) / 2;
        if (!node->left) node->left = new SegmentNode();
        if (!node->right) node->right = new SegmentNode();

        updateRange(node->left, start, mid, l, r, val);
        updateRange(node->right, mid + 1, end, l, r, val);

        node->val = node->left->val + node->right->val;
    }

    long long queryRange(SegmentNode* node, long long start, long long end, long long l, long long r) {
        if (!node || end < l || start > r) return 0;
 
        pushDown(node, start, end);

        if (start >= l && end <= r) {
            return node->val;
        }

        long long mid = start + (end - start) / 2;

        long long leftSum = queryRange(node->left, start, mid, l, r);
        long long rightSum = queryRange(node->right, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    void destroy(SegmentNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    DynamicLazySegmentTree(long long minR = 0, long long maxR = 1e9) {
        root = new SegmentNode();
        minRange = minR;
        maxRange = maxR;
    }

    ~DynamicLazySegmentTree() {
        destroy(root);
    }

    void update(long long left, long long right, long long val) {
        updateRange(root, minRange, maxRange, left, right, val);
    }

    long long query(long long left, long long right) {
        return queryRange(root, minRange, maxRange, left, right);
    }
};

int main() {
    DynamicLazySegmentTree st(0, 1e9);

    cout << "Adding 5 to range [10, 20]." << endl;
    st.update(10, 20, 5);

    cout << "Adding 10 to range [15, 500000000]." << endl;
    st.update(15, 500000000, 10);

    // [10, 14] has 5. (Length 5: 5 * 5 = 25)
    cout << "Sum in range [10, 14]: " << st.query(10, 14) << endl; 
    
    // [15, 20] has 5 + 10 = 15. (Length 6: 6 * 15 = 90)
    cout << "Sum in range [15, 20]: " << st.query(15, 20) << endl; 

    // Query [10, 20]: 25 + 90 = 115
    cout << "Sum in range [10, 20]: " << st.query(10, 20) << endl;

    // Output sum of the massive updated range
    // Elements [21, 500000000] have 10. Length is 499,999,980. Sum = 4,999,999,800.
    // Total sum = 115 + 4,999,999,800 = 4,999,999,915.
    cout << "Sum in range [0, 1000000000]: " << st.query(0, 1e9) << endl;

    return 0;
}