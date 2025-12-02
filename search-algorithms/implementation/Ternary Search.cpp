#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(log n)
int ternarySearch(vector<int>& arr, int start, int end, int target) {
    if (end >= start) {
        int mid1 = start + (end - start) / 3;
        int mid2 = end - (end - start) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        // 1. Target is in the left one-third
        if (target < arr[mid1]) {
            return ternarySearch(arr, start, mid1 - 1, target);
        }
        // 2. Target is in the right one-third
        else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, end, target);
        }
        // 3. Target is in the middle one-third
        else return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
    }
    
    return -1;
}