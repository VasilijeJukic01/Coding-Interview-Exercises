class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        vector<vector<int>> result;
        
        long long BASE = 256;
        long long MOD = 1e9 + 7;

        for (int i = 0; i < words.size(); i++) {
            map[words[i]] = i;
        }

        for (int k = 0; k < words.size(); k++) {
            string w = words[k];
            
            // Full word is reversed in the map
            string reversed = w;
            reverse(reversed.begin(), reversed.end());
            if (map.count(reversed) && map[reversed] != k) {
                result.push_back({map[reversed], k});
            }

            long long prefHash = 0;
            long long suffHash = 0;
            long long h = 1;
            
            // Prefix
            for (int i = 0; i < w.size(); i++) {
                prefHash = (prefHash * BASE + w[i]) % MOD;
                suffHash = (w[i] * h + suffHash) % MOD;
                h = (h * BASE) % MOD;

                if (prefHash == suffHash) {
                    string need = w.substr(i + 1);
                    reverse(need.begin(), need.end());
                    
                    if (map.count(need) && map[need] != k) {
                        result.push_back({map[need], k});
                        if (need.empty()) {
                            result.push_back({k, map[need]});
                        }
                    }
                }
            }

            prefHash = 0, suffHash = 0; 
            h = 1;
            
            // Suffix
            for (int i = 0; i < reversed.size(); i++) {
                prefHash = (prefHash * BASE + reversed[i]) % MOD;
                suffHash = (reversed[i] * h + suffHash) % MOD;
                h = (h * BASE) % MOD;

                if (prefHash == suffHash) {
                    string need = reversed.substr(i + 1);
                    
                    if (!need.empty() && map.count(need) && map[need] != k) {
                        result.push_back({k, map[need]});
                    }
                }
            }
        }

        return result;
    }
};