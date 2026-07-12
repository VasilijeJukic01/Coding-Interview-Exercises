class Solution {
    using p = array<int, 2>;
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<p> filtered;

        for (int i = 0; i < n; i++) {
            filtered.push_back({arr[i], i});
        }

        sort(filtered.begin(), filtered.end());

        vector<int> result(n, 1);
        int rank = 2;
        for (int i = 1; i < n; i++) {
            if (filtered[i][0] == filtered[i - 1][0]) {
                result[filtered[i][1]] = result[filtered[i - 1][1]];
            }
            else result[filtered[i][1]] = rank++;
        }

        return result;
    }
};