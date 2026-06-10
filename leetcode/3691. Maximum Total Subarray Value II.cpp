class SegmentTree {
private:
    // {min, max} in range
    vector<array<long long, 2>> tree;
public:
    SegmentTree(int n) {
        tree.resize(4 * n);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = {nums[start], nums[start]};
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        build(nums, leftChild, start, mid);
        build(nums, rightChild, mid + 1, end);

        long long maxVal = max(tree[leftChild][1], tree[rightChild][1]);
        long long minVal = min(tree[leftChild][0], tree[rightChild][0]);

        tree[node] = {minVal, maxVal};
    }

    array<long long, 2> query(int node, int start, int end, int left, int right) {
        if (end < left || start > right) return {LLONG_MAX, LLONG_MIN};
        if (start >= left && end <= right) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        array<long long, 2> lRes = query(leftChild, start, mid, left, right);
        array<long long, 2> rRes = query(rightChild, mid + 1, end, left, right);

        return {min(lRes[0], rRes[0]), max(lRes[1], rRes[1])};
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree st(n);
        st.build(nums, 0, 0, n - 1);

        priority_queue<tuple<long long, int, int>> pq;
        // {left, right}
        set<pair<int, int>> visited;

        array<long long, 2> start = st.query(0, 0, n - 1, 0, n - 1);
        pq.push({start[1] - start[0], 0, n - 1});
        visited.insert({0, n - 1});

        long long total = 0;

        // Best First Search
        while (k > 0 && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            total += val;
            k--;

            if (l < r) {
                // Shrink left
                if (visited.find({l + 1, r}) == visited.end()) {
                    visited.insert({l + 1, r});
                    array<long long, 2> res = st.query(0, 0, n - 1, l + 1, r);
                    pq.push({res[1] - res[0], l + 1, r});
                }
                // Shrink right
                if (visited.find({l, r - 1}) == visited.end()) {
                    visited.insert({l, r - 1});
                    array<long long, 2> res = st.query(0, 0, n - 1, l, r - 1);
                    pq.push({res[1] - res[0], l, r - 1});
                }
            }
        }

        return total;
    }
};