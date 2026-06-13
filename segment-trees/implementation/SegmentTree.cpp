/*
 * Segment Tree Implementation (Point Update, Range Query)
 *
 * Logic:
 * - Builds a binary tree where each node represents an interval [L, R].
 * - Leaves represent individual elements from the array.
 * - Internal nodes represent the merged result of their children.
 *
 * Time Complexity: 
 * - Build: O(N)
 * - Point Update: O(log N)
 * - Range Query: O(log N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
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

    void update(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (index <= mid) {
            update(leftChild, start, mid, index, val);
        } else {
            update(rightChild, mid + 1, end, index, val);
        }

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    int query(int node, int start, int end, int left, int right) {
        if (end < left || start > right) return 0;
        if (start >= left && end <= right) return tree[node];

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = query(leftChild, start, mid, left, right);
        int rightSum = query(rightChild, mid + 1, end, left, right);

        return leftSum + rightSum;
    }

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(4 * n, 0);
            build(nums, 0, 0, n - 1);
        }
    }

    void update(int index, int val) {
        update(0, 0, n - 1, index, val);
    }

    int query(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree st(nums);

    cout << "Sum of values in range [1, 3]: " << st.query(1, 3) << endl; // 3+5+7 = 15
    st.update(1, 10);
    cout << "Sum of values in range [1, 3] after update: " << st.query(1, 3) << endl; // 10+5+7 = 22

    return 0;
}