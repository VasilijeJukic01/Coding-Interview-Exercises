/*
A curator has paintings from different years. She wants guests to see them in chronological order. 
However, her eccentric rule is:

1. Guest views the top painting, then places it in the exhibit.
2. Guest takes the next top painting and moves it to the very bottom of their hand.
3. Repeat until all paintings are placed.

Given the years on the paintings, find the initial order the curator must hold them in her hand so that they are 
placed in the exhibit in strictly increasing order.

Input:
Years: [1920, 1850, 2010, 1780]

Output:
[1780, 1920, 1850, 2010]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int>& years) {
    int n = years.size();
    sort(years.begin(), years.end());

    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    vector<int> result(n);
    for (int year : years) {
        result[q.front()] = year;
        q.pop();

        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }
    return result;
}

int main() {
    vector<int> years = {1920, 1850, 2010, 1780};
    vector<int> order = solve(years);

    for (int y : order) {
        cout << y << " ";
    }

    return 0;
}