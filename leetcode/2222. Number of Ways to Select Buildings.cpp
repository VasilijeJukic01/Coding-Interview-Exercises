class Solution {
    using ll = long long;
    using table = vector<vector<ll>>;
public:
    ll numberOfWays(string s) {
        int n = s.size();

        table curr(3, vector<ll>(4, 0));
        table next(3, vector<ll>(4, 0));
        for (int prev = 2; prev >= 0; prev--) {
            curr[prev][0] = 1;
            next[prev][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = 2; prev >= 0; prev--) {
                for (int limit = 3; limit > 0; limit--) {
                    ll skip = next[prev][limit];
                    ll use = 0;

                    if (prev == 0) {
                        if (s[i] == '1') use = next[1][limit - 1];
                    }
                    else if (prev == 1) {
                        if (s[i] == '0') use = next[0][limit - 1];
                    }
                    else if (prev == 2) {
                        use = next[s[i] - '0'][limit - 1];
                    }

                    curr[prev][limit] = skip + use;
                }
            }
            next = curr;
        }

        return curr[2][3];
    }
};