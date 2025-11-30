class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> result;

        vector<int> mins(matrix.size(), INT_MAX);
        vector<int> maxs(matrix[0].size(), INT_MIN);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                mins[i] = min(mins[i], matrix[i][j]);
                maxs[j] = max(maxs[j], matrix[i][j]);
            }
        }

        for (int i = 0; i < mins.size(); i++) {
            for (int j = 0; j < maxs.size(); j++) {
                if (mins[i] == maxs[j]) result.push_back(mins[i]);
            }
        }

        return result;
    }
};