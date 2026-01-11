/*
* Bubble Sort
 *
 * Logic:
 * - Repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
 * - The pass is repeated until the list is sorted.
 * - Optimization: A swapped flag detects if a pass completed without swaps (list already sorted).
 *
 * Time Complexity: O(N^2) Average/Worst, O(N) Best (already sorted).
 * Space Complexity: O(1).
 * Stability: Stable.
 */

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped) break;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}