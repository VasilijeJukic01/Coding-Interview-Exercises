/*
During a dry summer, several families stand in a line at the only communal well. Each family carries a different 
number of empty pitchers. The well fills exactly one pitcher at a time (taking 1 minute). Once a family gets one 
pitcher filled, if they still have more empty ones, they must walk to the back of the line and wait for their turn 
again. If their pitchers are all full, they leave the line.

Given an array of integers representing the pitchers each family needs, and an index K representing your friend's 
position in the initial line, calculate the total minutes passed until your friend’s last pitcher is full.

Input: [5, 2, 3], K: 2
Output: 8 minutes
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<int>& pitchers, int k) {
    // {remaining, index}
    queue<pair<int, int>> q;
    int total = 0;

    for (int i = 0; i < pitchers.size(); i++) {
        q.push({pitchers[i], i});
    }

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        total++;
        current.first--;

        if (current.second == k && current.first == 0) {
            return total;
        }

        if (current.first > 0) q.push(current);
    }
    return total;
}

int main() {
    vector<int> pitchers = {5, 2, 3};
    int k = 2;

    cout << solve(pitchers, k);

    return 0;
}