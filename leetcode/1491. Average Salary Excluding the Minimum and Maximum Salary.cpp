class Solution {
public:
    double average(vector<int>& salary) {
        int lb = INT_MAX, ub = INT_MIN;
        for (int i = 0; i < salary.size(); i++) {
            lb = min(lb, salary[i]);
            ub = max(ub, salary[i]);
        }

        int total = 0;
        for (int i = 0; i < salary.size(); i++) {
            if (salary[i] != lb && salary[i] != ub) {
                total += salary[i];
            }
        }

        return (double) total / (salary.size() - 2);
    }
};