/*
* Selection Sort
 *
 * Logic:
 * - Divides the input list into two parts: the sublist of items already sorted and the sublist of items remaining.
 * - Finds the minimum element in the unsorted sublist and swaps it with the leftmost unsorted element.
 *
 * Time Complexity: O(N^2) always.
 * Space Complexity: O(1).
 * Stability: Unstable (depends on implementation, typically unstable).
 */

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}