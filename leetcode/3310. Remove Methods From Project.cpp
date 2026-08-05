class Solution {
    using vv = vector<vector<int>>;
public:
    vector<int> remainingMethods(int n, int k, vv& invocations) {
        vv adjList(n);
        for (auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            adjList[u].push_back(v);
        }

        unordered_set<int> susMethods;
        queue<int> q;
        unordered_set<int> visited;

        q.push(k);
        visited.insert(k);
        while (!q.empty()) {
            int u = q.front();
            susMethods.insert(u);
            q.pop();

            for (auto& v : adjList[u]) {
                if (visited.count(v)) continue;
                visited.insert(v);
                q.push(v);
            }
        }

        for (auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            bool uState = susMethods.count(u);
            bool vState = susMethods.count(v);

            if (vState == true && uState == false) {
                vector<int> result;
                for (int i = 0; i < n; i++) {
                    result.push_back(i);
                }
                return result;
            }
        }

        vector<bool> filtered(n, true);
        for (auto& m : susMethods) {
            filtered[m] = false;
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (filtered[i]) result.push_back(i);
        }

        return result;
    }
};