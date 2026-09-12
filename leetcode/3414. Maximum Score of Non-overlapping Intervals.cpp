class Solution {
    using ll = long long;
    using p = pair<ll, vector<int>>;
    using table = vector<vector<p>>;
public:
    int findNext(vector<vector<int>>& intervals, int index) {
        int n = intervals.size();
        int start = index + 1, end = n - 1;

        int next = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            vector<int>& interval = intervals[mid];
            vector<int>& target = intervals[index];

            if (interval[0] > target[1]) {
                next = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return next;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        table dp(n + 1, vector<p>(5, {0, {}}));
        for (int i = n - 1; i >= 0; i--) {
            for (int cap = 4; cap > 0; cap--) {
                // Skip
                p skip = dp[i + 1][cap];
                // Take
                int nextI = findNext(intervals, i);
                p take = dp[nextI][cap - 1];
                take.first += intervals[i][2];
                take.second.push_back(intervals[i][3]);

                p result;
                if (take.first == skip.first) {
                    sort(take.second.begin(), take.second.end());
                    sort(skip.second.begin(), skip.second.end());
                    if (take.second < skip.second) result = take;
                    else result = skip;
                }
                else if (take.first > skip.first) result = take;
                else result = skip;

                dp[i][cap] = result;
            }
        }

        p result = dp[0][4];
        sort(result.second.begin(), result.second.end());

        return result.second;
    }
};