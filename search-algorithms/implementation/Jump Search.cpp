#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Time Complexity: O(sqrt(n))
int jumpSearch(vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    // Finding the block where the element is present
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    // Linear search for x in block beginning with prev
    while (arr[prev] < target) {
        prev++;
        // If we reached next block or end of array, element is not present
        if (prev == min(step, n)) return -1;
    }

    if (arr[prev] == target) return prev;

    return -1;
}