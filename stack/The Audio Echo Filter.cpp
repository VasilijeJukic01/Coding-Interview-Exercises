/*
You are an audio engineer processing a raw sound wave represented by an array of integers, decibels.
For a specific audio effect called Forward Masking, you need to analyze every sample point. For each sample 
at index i, you need to calculate the lag (in number of samples) until the next sample that is strictly louder.
If there is no future sample louder than the current one, the lag is 0.

Input: decibels = [70, 72, 68, 65, 75, 70]
Output: [1, 3, 2, 1, 0, 0]
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int>& decibels) {
    int n = decibels.size();
    vector<int> lag(n, 0);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && decibels[i] > decibels[s.top()]) {
            int prev = s.top();
            s.pop();
            lag[prev] = i - prev;
        }
        s.push(i);
    }

    return lag;
}

int main() {
    vector<int> d = {70, 72, 68, 65, 75, 70};

    vector<int> v = solve(d);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    
    return 0;
}