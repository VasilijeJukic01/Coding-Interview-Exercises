/**
In a galaxy cluster, communication signals are amplified across n relay stations. Each station amplifies the signal by 
raising its strength s to a power determined by a sequence of exponents provided in an array exponents. However, the 
signal strength must be computed modulo m to prevent overflow. Additionally, some stations are "boosters" that double 
the signal before applying the exponentiation. Given the base signal strength s, an array of exponents, a list of booster 
station indices, and a modulus m, compute the final signal strength after all stations.

Input
s: Base signal strength (1 ≤ s ≤ 10^9)
exponents: Array of exponents [e1, e2, ..., en] (1 ≤ ei ≤ 10^9, 1 ≤ n ≤ 10^5)
boosters: Array of booster station indices (0-based, 0 ≤ boosters[i] < n)
m: Modulus (1 ≤ m ≤ 10^9)

Output
Return the final signal strength modulo m.

Example 1
Input: s = 2, exponents = [2, 3], boosters = [0], m = 1000
Output: 96
Explanation: 
- Station 0 (booster): Signal = (2 * 2)^2 = 4^2 = 16
- Station 1: Signal = 16^3 = 4096 % 1000 = 96

Example 2
Input: s = 2, exponents = [2, 3, 1], boosters = [0, 1, 2], m = 1000
Output: 536
Explanation:
- Station 0 (booster): (2 * 2)^2 = 4^2 = 16.
- Station 1 (booster): (16 * 2)^3 = 32^3 = 32768 % 1000 = 768.
- Station 2 (booster): (768 * 2)^1 = 1536 % 1000 = 536.

Constraints:
1 ≤ s, m ≤ 10^9
1 ≤ n ≤ 10^5
0 ≤ boosters.length ≤ n
1 ≤ exponents[i] ≤ 10^9
*/

#include <iostream>
#include <vector>
#include <unordered_set>

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

long long solve(long long s, vector<int> exponents, vector<int> boosters, long long mod) {
    unordered_set<int> boostersSet(boosters.begin(), boosters.end());
    
    for (int i = 0; i < exponents.size(); i++) {
        if (boostersSet.count(i)) {
            s = fast_expo((s * 2) % mod, exponents[i], mod);
        } 
        else s = fast_expo(s, exponents[i], mod);
    }
    
    return s;
}

int main() {
    long long s = 2, mod = 1000;
    vector<int> exponents = {2, 3, 1};
    vector<int> boosters = {0, 1, 2};

    cout << solve(s, exponents, boosters, mod);
    
    return 0;
}
