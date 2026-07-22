class SegmentTree {
private:
    vector<int> tree;
public:
    SegmentTree(int n) {
        tree.resize(4 * n);
    }

    void build(vector<int>& a, int node, int s, int e) {
        if (s == e) {
            tree[node] = a[s];
            return;
        }

        int mid = s + (e - s) / 2;
        int left = 2 * node + 1, right = 2 * node + 2;
        build(a, left, s, mid);
        build(a, right, mid + 1, e);

        tree[node] = max(tree[left], tree[right]);
    }

    int query(int node, int s, int e, int l, int r) {
        if (e < l || s > r) return 0;
        if (s >= l && e <= r) {
            return tree[node];
        }

        int mid = s + (e - s) / 2;
        int leftRes = query(2 * node + 1, s, mid, l, r);
        int rightRes = query(2 * node + 2, mid + 1, e, l, r);

        return max(leftRes, rightRes);
    }
};

class Solution {
    using v = vector<int>;
    using vv = vector<vector<int>>;
public:
    int overlap(vector<array<int, 2>>& blocks, int i, int l, int r) {
        int blockStart = max(blocks[i][0], l);
        int blockEnd = min(blocks[i][1], r);

        return max(0, blockEnd - blockStart + 1);
    }

    v maxActiveSectionsAfterTrade(string s, vv& queries) {
        int n = s.size();

        vector<array<int, 2>> blocks;
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (start == -1) start = i;
            }
            else {
                if (start != -1) {
                    blocks.push_back({start, i - 1});
                    start = -1;
                }
            }
        }
        if (start != -1) blocks.push_back({start, n - 1});

        int m = blocks.size(); 
        SegmentTree st(m);

        vector<int> adjSums;
        if (m > 1) {
            for (int i = 0; i < m - 1; i++) {
                int leftSum = blocks[i][1] - blocks[i][0] + 1;
                int rightSum = blocks[i + 1][1] - blocks[i + 1][0] + 1;
                adjSums.push_back(leftSum + rightSum);
            }
            st.build(adjSums, 0, 0, m - 2);
        }
        
        int ones = count(s.begin(), s.end(), '1');

        // blocks = [[0,1],[3,5],[7,7],[9,12]]
        // adj = [5,4,5]
        vector<int> result;
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            // [l, r] = [0, 12]

            int startI = -1;
            int start = 0, end = m - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                // mid = 1, block = [3,5]
                // 5 > 0 -> find earlier if possible
                if (blocks[mid][1] >= l) {
                    startI = mid;
                    end = mid - 1;
                }
                else start = mid + 1;
            }

            int endI = -1;
            start = 0, end = m - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                // mid = 1, block = [3,5]
                // 3 < 12 -> find next if possible
                if (blocks[mid][0] <= r) {
                    endI = mid;
                    start = mid + 1;
                }
                else end = mid - 1;
            }

            // 0 or 1 blocks overlap -> not enough
            if (startI == -1 || endI == -1 || startI >= endI) {
                result.push_back(ones);
                continue;
            }

            // 2 blocks overlap
            if (endI == startI + 1) {
                int zerosLeft = overlap(blocks, startI, l, r);
                int zerosRight = overlap(blocks, endI, l, r);
                result.push_back(ones + zerosLeft + zerosRight);
            }
            // > 2 blocks overlap
            else {         
                // Merge first pair
                // [0,1] + [3,5]
                int first = overlap(blocks, startI, l, r) + overlap(blocks, startI + 1, l, r);
                
                // Merge last pair
                // [7,7] + [9,12]
                int last = overlap(blocks, endI - 1, l, r) + overlap(blocks, endI, l, r);
                
                // Inside [l, r]
                int middle = 0;
                if (endI - 1 >= startI + 2) {
                    middle = st.query(0, 0, m - 2, startI + 1, endI - 2);
                }
                
                int zeros = max({first, last, middle});
                result.push_back(ones + zeros);
            }
        }

        return result;
    }
};