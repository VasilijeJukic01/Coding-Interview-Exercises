class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<long long, int> hashes;
        
        long long MOD = 1e9 + 7;
        long long BASE = 256;
        for (auto& p : patterns) {
            long long hash = 0;
            for (int i = 0; i < p.size(); i++) {
                hash = (hash * BASE + p[i]) % MOD;
            }
            hashes[hash]++;
        }

        int total = 0;
        for (int i = 0; i < word.size(); i++) {
            long long hash = 0;
            for (int j = i; j < word.size(); j++) {
                hash = (hash * BASE + word[j]) % MOD;
                if (hashes[hash] != 0) {
                    total += hashes[hash];
                    hashes.erase(hash);
                }
            }
        }

        return total;
    }
};