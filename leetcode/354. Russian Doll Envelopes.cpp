class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& e1, const vector<int>& e2){
                return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);

        });

        vector<int> dp;
        dp.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++) {
            if (envelopes[i][1] > dp.back()) {
                dp.push_back(envelopes[i][1]);
            }
            else {
                int write = 0;
                int start = 0, end = dp.size() - 1;
                while (start <= end) {
                    int mid = start + (end - start) / 2;

                    if (envelopes[i][1] <= dp[mid]) {
                        end = mid - 1;
                        write = mid;
                    }
                    else start = mid + 1;
                }
                dp[write] = envelopes[i][1];
            }
        }

        return dp.size();
    }
};