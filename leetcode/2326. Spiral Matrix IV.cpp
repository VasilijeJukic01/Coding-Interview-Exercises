/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int dir = 0;
        int i = 0, j = 0;
        while (head) {
            int nI = i + dy[dir], nJ = j + dx[dir];
            if (isSafe(nI, nJ, m, n) && mat[nI][nJ] == -1) {
                mat[i][j] = head->val;
                i = nI;
                j = nJ;
            }
            else {
                dir = (dir + 1) % 4;
                mat[i][j] = head->val;
                i = i + dy[dir];
                j = j + dx[dir];
            }
            head = head->next;
        }

        return mat;
    }
};