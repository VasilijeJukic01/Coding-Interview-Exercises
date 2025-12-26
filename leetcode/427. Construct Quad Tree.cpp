/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int sameValues(vector<vector<int>>& grid, int k, int x, int y) {
        bool ones = false;
        bool zeros = false;
        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                if (grid[i][j] == 1) ones = true;
                else zeros = true;

                if (ones && zeros) return -1;
            }
        }

        return ones ? 1 : 0;
    }

    Node* constructUtil(vector<vector<int>>& grid, int k, int x, int y) {
        int val = sameValues(grid, k, x, y);
        Node* root = new Node(val, true);

        if (val == 1 || val == 0) return root;

        int s = k / 2;
        root->isLeaf = false;
        root->topLeft = constructUtil(grid, s, x, y);
        root->topRight = constructUtil(grid, s, x, y + s);
        root->bottomLeft = constructUtil(grid, s, x + s, y);
        root->bottomRight = constructUtil(grid, s, x + s, y + s);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        return constructUtil(grid, grid.size(), 0, 0);
    }
};