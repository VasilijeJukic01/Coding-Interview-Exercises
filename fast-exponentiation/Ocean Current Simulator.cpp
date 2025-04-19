/**
An ocean current model predicts water flow through a grid of n x m cells. Each cell (i, j) has a "flow factor" computed 
as b^(d[i][j]) % mod, where b is the base current strength and d[i][j] is the depth at cell (i, j). However, the total flow 
through the grid is the product of flow factors for cells in a given path from (0, 0) to (n-1, m-1), moving only right or down. 
Compute the total flow modulo mod for the path with the maximum flow product.

Input
b: Base current strength (1 ≤ b ≤ 10^6)
d: 2D array of depths [n][m] (0 ≤ d[i][j] ≤ 10^9)
mod: Modulus (1 ≤ mod ≤ 10^9)

Output
Return the maximum flow product modulo mod for any valid path.

Example 1
Input: b = 2, d = [[1, 2], [3, 4]], mod = 1000
Output: 256
Explanation:
- Possible paths:
  - (0,0) -> (0,1) -> (1,1): Flow = 2^1 * 2^2 * 2^4 = 2 * 4 * 16 = 128
  - (0,0) -> (1,0) -> (1,1): Flow = 2^1 * 2^3 * 2^4 = 2 * 8 * 16 = 256
- Maximum flow = 256 % 1000 = 256

Example 2
Input: b = 2, d = [[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]], mod = 10000
Output: 5456

Constraints:
1 ≤ n, m ≤ 100
1 ≤ b, mod ≤ 10^9
0 ≤ d[i][j] ≤ 10^9
*/

#include <iostream>
#include <vector>

using namespace std;

long long fast_expo(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent) {
        if (exponent & 1) result = (result * base) % mod;
        
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return result;
}

long long solve(long long b, vector<vector<long long>> d, long long mod) {
    int n = d.size(), m = d[0].size();
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    
    dp[0][0] = fast_expo(b, d[0][0], mod);
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i-1][0] * fast_expo(b, d[i][0], mod)) % mod;
    }
    
    for (int j = 1; j < m; j++) {
        dp[0][j] = (dp[0][j-1] * fast_expo(b, d[0][j], mod)) % mod;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            long long c = fast_expo(b, d[i][j], mod);
            dp[i][j] = (max(dp[i-1][j], dp[i][j-1]) * c) % mod;
        }
    }
    
    return dp[n-1][m-1];
    
}

int main() {
    long long b = 2, mod = 10000;
    vector<vector<long long>> d = {
        { 1, 2, 3, 4 }, 
        { 2, 3, 4, 5 }, 
        { 3, 4, 5, 6 }, 
        { 4, 5, 6, 7 }
    };

    cout << solve(b, d, mod);
    
    return 0;
}
