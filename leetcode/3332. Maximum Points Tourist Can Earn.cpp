class Solution {
    using vvi = vector<vector<int>>;
    using table = vector<vector<int>>;
public:
    int maxScore(int n, int k, vvi& stayScore, vvi& travelScore) {
        int maxScore = 0;

        table dp(n, vector<int>(k + 1, 0));
        for (int daysLeft = 1; daysLeft <= k; daysLeft++) {
            for (int city = 0; city < n; city++) {
                int stay = stayScore[k - daysLeft][city] + dp[city][daysLeft - 1];

                int best = stay;
                for (int dest = 0; dest < n; dest++) {
                    int move = travelScore[city][dest] + dp[dest][daysLeft - 1];
                    best = max(best, move);
                }

                dp[city][daysLeft] = best;
            }
        }

        for (int start = 0; start < n; start++) {
            maxScore = max(maxScore, dp[start][k]);
        }

        return maxScore;
    }
};