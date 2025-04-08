/*
You’re a clock collector visiting a street with n shops, each offering a number of antique clocks for sale. 
The array clocks represents the number of clocks available, where clocks[i] is the number at shop i (0-based indexing). 
You can’t buy from adjacent shops due to a local rule limiting purchases on the same day.

You also have a special coupon: you can choose one shop in your sequence and double its clock count, but if you use 
this coupon on a shop, it becomes your last purchase (you cannot buy from any shops that come after it in the array). 
Your goal is to maximize the total number of clocks you collect by choosing a sequence of non-adjacent shops and 
deciding if and where to use the coupon.

Return the maximum number of clocks you can obtain.

Constraints:
1 <= n <= 1000
0 <= clocks[i] <= 1000

Example 1
Input: clocks = [1, 2, 3, 1]
Output: 7

Explanation:
Option 1: Buy from shop 0 (1 clock) and shop 2 (3 clocks), using the coupon on shop 2 to double it. Since shop 2 
(index 2) is the last purchase, you stop there:
Total = 1 + 2 * 3 = 1 + 6 = 7.
Option 2: Buy from shop 1 (2 clocks) and shop 3 (1 clock), using the coupon on shop 3:
Total = 2 + 2 * 1 = 2 + 2 = 4.
Option 3: Buy only from shop 2 (3 clocks), using the coupon on shop 2:
Total = 2 * 3 = 6.
Option 4: Buy from shop 0 (1 clock) and shop 2 (3 clocks) without the coupon:
Total = 1 + 3 = 4.
The best is Option 1: 7 clocks by buying from shops 0 and 2, doubling shop 2, and stopping (nothing after index 2 
is considered).

Example 2
Input: clocks = [2, 7, 9, 3, 1]
Output: 20

Explanation:
Option 1: Buy from shop 0 (2 clocks) and shop 2 (9 clocks), using the coupon on shop 2. Stop after shop 2:
Total = 2 + 2 * 9 = 2 + 18 = 20.
Option 2: Buy from shop 1 (7 clocks) and shop 3 (3 clocks), using the coupon on shop 3. Stop after shop 3:
Total = 7 + 2 * 3 = 7 + 6 = 13.
Option 3: Buy from shop 0 (2 clocks) and shop 2 (9 clocks) without the coupon:
Total = 2 + 9 = 11.
Option 4: Buy only from shop 2 (9 clocks), using the coupon on shop 2:
Total = 2 * 9 = 18.
Option 1 wins with 20 clocks: buy from shops 0 and 2, double shop 2 with the coupon, and finish (ignoring shops 3 and 4).
*/

#include <iostream>
#include <vector>

using namespace std;

int collectClocks(vector<int> clocks, int n) {
    if (clocks.empty()) return 0;
    if (n == 1) return clocks[0] * 2;
    
    vector<int> dp(n, 0);
    vector<int> bonus(n, 0);
    
    dp[0] = clocks[0];
    dp[1] = max(clocks[0], clocks[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + clocks[i]);
    }
    
    bonus[0] = clocks[0] * 2;
    bonus[1] = max(clocks[0] * 2, clocks[1] * 2);
    
    for (int i = 2; i < n; i++) {
        bonus[i] = max(dp[i - 1], dp[i - 2] + clocks[i] * 2);
    }
    
    int maxClocks = 0;
    for (int i = 0; i < n; i++) {
        maxClocks = max(maxClocks, dp[i]);
        maxClocks = max(maxClocks, bonus[i]);
    }
    
    return maxClocks;
}

int main() {
    vector<int> clocks = {3, 8, 2, 1, 4, 5};
    cout << collectClocks(clocks, clocks.size());

    return 0;
}
