/*
In the heart of the Mystic Forest, every creature must follow a special code to travel safely through the ancient, 
enchanted pathways. These paths are guarded by forest spirits who only allow travelers that follow a numeric trail 
of a certain kind. These trails are written as digit strings of length n.

A trail is considered enchanted if:
- Every digit at an even position (0-indexed) is an even number (0, 2, 4, 6, 8), representing calm and harmony 
  required to step on the moss-covered stones.
- Every digit at an odd position is a prime number (2, 3, 5, 7), representing bravery needed to pass under the 
  watchful eyes of spirit owls.

Example:
"2843" is enchanted: digits at even indices are 2 and 4 and digits at odd indices are 8 and 3.
"1475" is not enchanted: digit '1' is at an even index but is not even, so the spirits will not let you pass.

Given an integer n, return the total number of enchanted digit strings of length n that a creature could use. 
Since the forest is vast and the number can be large, return the result modulo 10⁹ + 7.

Input: n = 1
Output: 5
Explanation: Only even digits (0, 2, 4, 6, 8) can appear at position 0.

Input: n = 4
Output: 400
Explanation:
Positions 0 and 2 must be even → 5 choices each
Positions 1 and 3 must be prime → 4 choices each
Total: 5 × 4 × 5 × 4 = 400

Constraints:
1 <= n <= 10^5
Leading zeros are allowed.
*/

#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

long long fast_expo(long long base, long long exponent) {
    long long result = 1;
    while (exponent) {
        if (exponent & 1) result = (result * base) % MOD;
        
        base = (base * base) % MOD;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    int n = 4;
    
    int evens = (n + 1) / 2;
    int odds = n / 2;
    
    long long result = (fast_expo(5, evens) * fast_expo(4, odds)) % MOD;
    cout << result;
    
    return 0;
}
