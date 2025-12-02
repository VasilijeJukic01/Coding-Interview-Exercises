#include <iostream>
#include <vector>

using namespace std;

// Time Complexity O(log n)
// Space Complexity: O(log n)
int binarySearch(vector<int>& arr, int start, int end, int target) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) return mid;

        if (arr[mid] > target) return binarySearch(arr, start, mid - 1, target);
        return binarySearch(arr, mid + 1, end, target);
    }

    return -1;
}