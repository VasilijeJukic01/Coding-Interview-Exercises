/*
 * Lazy Segment Tree Implementation (Range Update, Range Query)
 *
 * Logic:
 * - Employs Lazy Propagation to delay updates to children until absolutely necessary.
 * - Stores pending updates in a lazy array.
 * - When a node is visited, pending lazy updates are applied (pushed down) before proceeding.
 *
 * Time Complexity:
 * - Build: O(N)
 * - Range Update: O(log N)
 * - Range Query: O(log N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

class LazySegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        build(nums, leftChild, start, mid);
        build(nums, rightChild, mid + 1, end);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Apply the pending update to the current node
            tree[node] += (end - start + 1) * lazy[node];

            // If not a leaf node, propagate the lazy value to children
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            // Clear current node's lazy value
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int left, int right, int val) {
        pushDown(node, start, end);

        if (end < left || start > right) return;

        // Node completely within bounds
        if (start >= left && end <= right) {
            lazy[node] += val;
            pushDown(node, start, end);
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        updateRange(leftChild, start, mid, left, right, val);
        updateRange(rightChild, mid + 1, end, left, right, val);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    int queryRange(int node, int start, int end, int left, int right) {
        pushDown(node, start, end);

        if (end < left || start > right) return 0;
        if (start >= left && end <= right) return tree[node];

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = queryRange(leftChild, start, mid, left, right);
        int rightSum = queryRange(rightChild, mid + 1, end, left, right);

        return leftSum + rightSum;
    }

public:
    LazySegmentTree(const vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(4 * n, 0);
            lazy.resize(4 * n, 0);
            build(nums, 0, 0, n - 1);
        }
    }

    void update(int left, int right, int val) {
        updateRange(0, 0, n - 1, left, right, val);
    }

    int query(int left, int right) {
        return queryRange(0, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    LazySegmentTree st(nums);

    cout << "Sum in range [1, 3]: " << st.query(1, 3) << endl; // 3+5+7 = 15
    
    st.update(1, 3, 2);
    cout << "Sum in range [1, 3] after range update: " << st.query(1, 3) << endl; // 5+7+9 = 21

    return 0;
}