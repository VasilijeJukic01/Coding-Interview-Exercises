/**
A group of rabbits is hiding in a row of burrows, represented by an array burrows where burrows[i] 
indicates the number of carrots in the i-th burrow. The rabbits want to collect as many carrots as 
possible, but they can only hop to a fixed number of consecutive burrows k due to their limited 
energy. Your task is to find the maximum number of carrots the rabbits can collect from any 
consecutive k burrows.

Input
burrows: An array of non-negative integers representing the number of carrots in each burrow.
k: An integer representing the size of the sliding window (number of consecutive burrows the 
rabbits can visit).

Output
Return an integer representing the maximum sum of carrots from any consecutive k burrows.

Constraints:
1 <= burrows.length <= 10^5
0 <= burrows[i] <= 10^4
1 <= k <= burrows.length

Example 1
Input: burrows = [2,3,1,5,4], k = 2
Output: 9
Explanation: The rabbits can collect 9 carrots by choosing burrows at indices 3 and 4 (5 + 4 = 9).

Example 2
Input: burrows = [1,2,3,1], k = 3
Output: 6
Explanation: The rabbits can collect 6 carrots by choosing burrows at indices 0, 1, and 2 (1 + 2 + 3 = 6).
*/

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> burrows, int k) {
    if (burrows.empty() || k == 0 || k > burrows.size()) return 0;
    
    int currentCarrots = 0, maxCarrots = 0;
    for (int i = 0; i < k; i++) {
        currentCarrots += burrows[i];
    }
    
    for (int i = k; i < burrows.size(); i++) {
        currentCarrots += burrows[i] - burrows[i - k];
        maxCarrots = max(maxCarrots, currentCarrots);
    }
    
    return maxCarrots;
}

int main() {
    vector<int> burrows = {2, 3, 1, 5, 4};
    int k = 2;
    
    cout << solve(burrows, k);
    
    return 0;
}
