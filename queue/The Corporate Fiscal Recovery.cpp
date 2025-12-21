/*
An auditor is looking at monthly profit/loss integers. The CEO wants to find the shortest period of consecutive 
months where the net total profit reached a target of at least X million dollars.
Note: Negative months (losses) make this tricky, as they can decrease the running total.

Find the length of the shortest period which sum is ≥ X. If none exists, return -1.

Input: 
MonthlyData: [2, -1, 2, 1, 5], Target (X): 7

Output: 3
[2, 1, 5]
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solve(const vector<int>& data, int X) {
    int n = data.size();

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + data[i];
    }

    int best = n + 1;
    deque<int> dq;

    for (int i = 0; i <= n; i++) {
        // Compress
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= X) {
            best = min(best, i - dq.front());
            dq.pop_front();
        }
        // Maintain strictly increasing
        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return (best <= n) ? best : -1;
}

int main() {
    vector<int> data = {2, -1, 2, 1, 5};
    int target = 7;

    cout << solve(data, target);
    
    return 0;
}