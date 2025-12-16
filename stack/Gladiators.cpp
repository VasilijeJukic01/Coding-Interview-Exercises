/*
A gladiator fights in an arena every day. You have a stream of numbers representing the gladiator's Performance Score
for that day. For every match, you want to calculate the gladiator's Legend Streak.

The streak is defined as the number of consecutive days just before (and including) today where the gladiator's score 
was less than or equal to today's score.

Example:
Input: [10, 20, 30, 25, 35, 15, 50]
Output: [1, 2, 3, 1, 5, 1, 7]
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int>& gladiators) {
    // {performance, streak}
    stack<pair<int, int>> s;
    vector<int> results;

    for (int score : gladiators) {
        int streak = 1;
        while (!s.empty() && s.top().first <= score) {
            streak += s.top().second;
            s.pop();
        }

        s.push({score, streak});
        results.push_back(streak);
    }

    return results;
}

int main() {
    vector<int> gladiators = {10, 20, 30, 25, 35, 15, 50};

    vector<int> v = solve(gladiators);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}