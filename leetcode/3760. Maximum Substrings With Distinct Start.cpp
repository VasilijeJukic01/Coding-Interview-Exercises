class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> visited;

        for (int i = 0; i < s.size(); i++) {
            if (visited.find(s[i]) == visited.end()) {
                visited.insert(s[i]);
            }
            if (visited.size() == 26) break;
        }

        return visited.size();
    }
};