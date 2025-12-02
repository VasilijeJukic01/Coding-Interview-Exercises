#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: θ(log(log n)), O(n)
int interpolationSearch(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    // Checking if target is within range
    while (start <= end && target >= arr[start] && target <= arr[end]) {
        
        // Prevent division by zero if all elements are same
        if (start == end) {
            if (arr[start] == target) return start;
            return -1;
        }

        // Probing the position with the formula
        int pos = start + (((double)(end - start) / (arr[end] - arr[start])) * (target - arr[start]));

        if (arr[pos] == target) return pos;

        if (arr[pos] < target) start = pos + 1;
        else end = pos - 1;
    }
    return -1;
}