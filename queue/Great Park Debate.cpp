/*
Two factions, the Arborists (A) and the Botanists (B), sit in a circle. They vote in turns (0 to N−1).
On a member's turn, they can Silence one person from the other faction. Silenced members are removed from all 
future voting. This continues in circles until only one faction remains.

Predict which faction wins based on the initial seating.

Input: "BAAB"
Output: Botanists

B(0) silences A(1).
A(2) silences B(3).
Back to B(0). B(0) silences A(2).
Only B(0) is left. Botanists win.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

string solve(string seating) {
    int n = seating.length();
    queue<int> arb, bot;

    for (int i = 0; i < n; i++) {
        if (seating[i] == 'A') arb.push(i);
        else bot.push(i);
    }

    while (!arb.empty() && !bot.empty()) {
        int aIdx = arb.front();
        arb.pop();
        int bIdx = bot.front();
        bot.pop();

        if (aIdx < bIdx) arb.push(aIdx + n);
        else bot.push(bIdx + n);
    }

    return arb.empty() ? "Botanists" : "Arborists";
}

int main() {
    string seating = "BAAB";
    cout << solve(seating);

    return 0;
}