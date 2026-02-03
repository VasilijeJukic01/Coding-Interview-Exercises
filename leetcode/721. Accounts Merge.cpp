class union_find {
private:
    vector<int> parent;
    vector<int> rank;
public:

    union_find(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }

    bool unite(int i, int j) {
        int parentI = find(i);
        int parentJ = find(j);

        if (parentI == parentJ) return false;
        if (rank[parentI] < rank[parentJ]) {
            parent[parentI] = parentJ; 
        }
        else if (rank[parentJ] < rank[parentI]) {
            parent[parentJ] = parentI;
        }
        else {
            parent[parentI] = parentJ;
            rank[parentJ]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        union_find uf(accounts.size());
        // {email, accId}
        unordered_map<string, int> emails;
        // {email, origin}
        unordered_map<string, int> map;

        // {accId, name}
        unordered_map<int, string> accNames;
        for (int i = 0; i < accounts.size(); i++) {
            accNames[i] = accounts[i][0];
            for (int e = 1; e < accounts[i].size(); e++) {
                emails[accounts[i][e]] = i;
                if (map.count(accounts[i][e])) {
                    uf.unite(map[accounts[i][e]], i);
                }
                else map[accounts[i][e]] = i;
            }
        }

        // {account, mails}
        unordered_map<int, set<string>> group;
        for (auto& [email, acc] : emails) {
            group[uf.find(acc)].insert(email);
        }

        vector<vector<string>> result;
        for (auto& [acc, emails] : group) {
            vector<string> data;
            data.push_back(accNames[acc]);
            for (auto& e : emails) {
                data.push_back(e);
            }
            result.push_back(data);
        }

        return result;
    }
};