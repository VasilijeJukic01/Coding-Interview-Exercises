class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;

        int currGas = 0;
        int totalGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            currGas = currGas - cost[i] + gas[i];
            totalGas = totalGas - cost[i] + gas[i];
            if (currGas < 0) {
                currGas = 0;
                start = i + 1;
            }
        }

        if (totalGas < 0) return -1;
        return start;
    }
};