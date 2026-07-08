// {number, digits}
using p = array<int, 2>;
const int MOD = 1e9 + 7;

class SegmentTree {
    vector<p> tree;
public:
    SegmentTree(int n) {
        tree.resize(4 * n);
    }

    long long myPow(int exp) {
        long long res = 1;
        long long base = 10;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    void build(string& s, int start, int end, int node) {
        if (start == end) {
            int count = s[start] == '0' ? 0 : 1;
            tree[node] = {s[start] - '0', count};
            return;
        }

        int mid = start + (end - start) / 2;
        int left = 2 * node + 1, right = 2 * node + 2;
        build(s, start, mid, left);
        build(s, mid + 1, end, right);

        p leftTree = tree[left];
        p rightTree = tree[right];
        if (leftTree[0] == 0) {
            tree[node] = rightTree;
        }
        else if (rightTree[0] == 0) {
            tree[node] = leftTree;
        }
        else {
            long long p = myPow(rightTree[1]);
            int count = leftTree[1] + rightTree[1];
            int num = ((leftTree[0] * p) % MOD + rightTree[0]) % MOD;
            tree[node] = {num, count};
        }
    }

    p query(int start, int end, int node, int l, int r) {
        if (end < l || start > r) return {0, 0};
        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        p leftRes = query(start, mid, left, l, r);
        p rightRes = query(mid + 1, end, right, l, r);

        if (leftRes[0] == 0) return rightRes;
        else if (rightRes[0] == 0) return leftRes;
        else {
            long long p = myPow(rightRes[1]);
            int count = leftRes[1] + rightRes[1];
            int num = ((leftRes[0] * p) % MOD + rightRes[0]) % MOD;
            return {num, count};
        }
    }
};

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + (s[i] - '0');
        }

        SegmentTree st(n);
        st.build(s, 0, n, 0);
        vector<int> result;
        for (auto& query : queries) {
            int l = query[0], r = query[1];

            int x = st.query(0, n, 0, l, r)[0];
            int sum = pSum[r + 1] - pSum[l];
            result.push_back((1LL * x * sum) % MOD);
        }
        return result;
    }
};