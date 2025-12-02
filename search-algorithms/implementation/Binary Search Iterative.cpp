#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(1)
int binarySearch(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) return mid;

        if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }

    return -1;
}