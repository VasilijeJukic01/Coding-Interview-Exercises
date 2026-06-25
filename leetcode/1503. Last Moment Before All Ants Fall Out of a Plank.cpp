class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int t = 0;

        for (int i = 0; i < left.size(); i++) {
            t = max(t, left[i]);
        }

        for (int i = 0; i < right.size(); i++) {
            t = max(t, n - right[i]);
        }

        return t;
    }
};