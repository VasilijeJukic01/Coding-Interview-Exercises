/*
You are given an array with unique elements of stalls[], which denote the positions of stalls.
You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls
to k cows such that the minimum distance between any two of them is the maximum possible.

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows in this case is 3, which is the largest among all possible ways.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can(vector<int>& v, int k, int d) {
    int total = 1;

    int prev = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] - prev >= d) {
            prev = v[i];
            total++;
        }
    }

    if (total >= k) return true;
    return false;
}

int main() {
    vector<int> v = {10, 1, 2, 7, 5};
    int k = 3;

    sort(v.begin(), v.end());

    int start = 0, end;
    for (int i = 0; i < v.size(); i++) {
        end = max(end, v[i]);
    }

    int best = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (can(v, k, mid)) {
            best = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }

    cout << best << endl;

    return 0;
}