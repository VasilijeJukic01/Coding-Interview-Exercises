class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n + 1);
        vector<int> outdeg(n + 1);

        for (auto& t : trust) {
            int u = t[0];
            int v = t[1];
            outdeg[u]++;
            indeg[v]++;
        }

        int judge = -1;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == n - 1 && outdeg[i] == 0) judge = i;
        }

        return judge;   
    }
};