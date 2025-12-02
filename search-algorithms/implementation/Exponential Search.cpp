#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time Complexity: O(log n)
int binarySearch(vector<int>& arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int target) {
    int n = arr.size();
    
    // If target is at the first position
    if (n > 0 && arr[0] == target) return 0;

    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2;
    }

    // Call binary search for the found range
    return binarySearch(arr, i / 2, min(i, n - 1), target);
}