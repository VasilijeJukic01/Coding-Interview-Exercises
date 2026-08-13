struct Node {
    int size;
    int maxLen;
    int prefLen, suffLen;
    char prefChar, suffChar;

    Node(int size, char prefChar, char suffChar) {
        this->size = size;
        this->prefChar = prefChar;
        this->suffChar = suffChar;
    }

    Node(char ch) {
        this->prefChar = ch;
        this->suffChar = ch;
        this->size = 1;
        this->prefLen = 1;
        this->suffLen = 1;
        this->maxLen = 1;
    }

    Node() {}
};

class SegmentTree {
    vector<Node> tree;
public:
    SegmentTree(int n) {
        tree.resize(4 * n);
    }

    Node merge(Node& left, Node& right) {
        Node node(left.size + right.size, left.prefChar, right.suffChar);

        // Extending left prefix to the right
        if (left.prefLen == left.size && left.prefChar == right.prefChar) {
            node.prefLen = left.size + right.prefLen;
        }
        else node.prefLen = left.prefLen;

        // Extending right suffix to the left
        if (right.suffLen == right.size && right.suffChar == left.suffChar) {
            node.suffLen = right.size + left.suffLen;
        }
        else node.suffLen = right.suffLen;
        
        node.maxLen = max(left.maxLen, right.maxLen);
        if (left.suffChar == right.prefChar) {
            node.maxLen = max(node.maxLen, left.suffLen + right.prefLen);
        }

        return node;
    }

    void build(string& s, int start, int end, int node) {
        if (start == end) {
            tree[node] = Node(s[start]);
            return;
        }

        int mid = start + (end - start) / 2;
        build(s, start, mid, 2 * node + 1);
        build(s, mid + 1, end, 2 * node + 2);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(string& s, int start, int end, int node, int index) {
        if (start == end) {
            if (start == index) tree[node] = Node(s[index]);
            return;
        }

        int mid = start + (end - start) / 2;
        if (index <= mid) update(s, start, mid, 2 * node + 1, index);
        else update(s, mid + 1, end, 2 * node + 2, index);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int root() {
        return tree[0].maxLen;
    }
};

class Solution {
    using v = vector<int>;
public:
    v longestRepeating(string s, string queryCharacters, v& queryIndices) {
        int n = s.size();

        SegmentTree st(n);
        st.build(s, 0, n - 1, 0);

        v result;
        for (int i = 0; i < queryIndices.size(); i++) {
            int index = queryIndices[i];
            s[index] = queryCharacters[i];
            st.update(s, 0, n - 1, 0, index);

            result.push_back(st.root());
        }

        return result;
    }
};