class Solution {
    using ll = long long;
    using v = vector<int>;
    using vv = vector<vector<int>>;
public:
    bool can(v& monsters, vector<ll>& bonus, ll mid) {
        ll curr = mid;
        for (int i = 0; i < monsters.size(); i++) {
            if (curr + bonus[i] < monsters[i]) {
                return false;
            }
            curr -= monsters[i];
            if (curr < 0) curr = 0;
        }

        return true;
    }
    
    ll minInitialStrength(v& monsters, vv& boosts) {
        int n = monsters.size();
        
        vector<ll> diff(n + 1, 0);
        for (auto& b : boosts) {
            int l = b[0], r = b[1];
            int v = b[2];

            diff[l] += v;
            if (r + 1 < n) diff[r + 1] -= v;
        }

        vector<ll> bonus(n, 0);
        ll curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diff[i];
            bonus[i] = curr;
        }

        ll start = 0;
        ll end = accumulate(monsters.begin(), monsters.end(), 0LL);

        ll best = end;
        while (start <= end) {
            ll mid = start + (end - start) / 2;
            if (can(monsters, bonus, mid)) {
                best = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return best;
    }
};