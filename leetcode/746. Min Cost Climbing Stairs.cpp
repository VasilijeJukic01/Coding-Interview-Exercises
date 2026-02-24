class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = 0, second = 0;

        int curr;
        for (int i = 2; i <= n; i++) {
            int option1 = first + cost[i - 2];
            int option2 = second + cost[i - 1];
            curr = min(option1, option2);

            first = second;
            second = curr;
        }

        return curr;
    }
};