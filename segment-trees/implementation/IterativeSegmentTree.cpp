/*
 * Iterative Segment Tree Implementation
 *
 * Logic:
 * - A highly optimized, non-recursive segment tree.
 * - Stores elements and bounds in a 1D array using exactly 2 * N space.
 * - Elements are stored at indices [N, 2N-1], and internal nodes at [1, N-1].
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

class IterativeSegmentTree {
private:
    vector<int> tree;
    int n;

public:
    IterativeSegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n, 0);

        // Insert leaves
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }

        // Build the tree by calculating parents
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    void update(int index, int val) {
        // Set value at leaf node
        index += n;
        tree[index] = val;

        // Move upward and update parents
        for (index >>= 1; index > 0; index >>= 1) {
            tree[index] = tree[index << 1] + tree[index << 1 | 1];
        }
    }

    int query(int left, int right) {
        int res = 0;
        left += n;
        right += n + 1; // Increment right bound since loop condition checks strictly <

        while (left < right) {
			// If left is a right child, process it and jump
            if (left & 1) res += tree[left++];
			// If right is a right child, process its left sibling
            if (right & 1) res += tree[--right];
            left >>= 1;
            right >>= 1;
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    IterativeSegmentTree st(nums);

    cout << "Sum in range [1, 3]: " << st.query(1, 3) << endl; // 3+5+7 = 15
    
    st.update(1, 10);
    cout << "Sum in range [1, 3] after update: " << st.query(1, 3) << endl; // 10+5+7 = 22

    return 0;
}