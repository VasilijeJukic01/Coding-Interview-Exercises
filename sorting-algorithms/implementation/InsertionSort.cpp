/*
* Insertion Sort
 *
 * Logic:
 * - Builds the final sorted array one item at a time.
 * - Takes an element and shifts previous larger elements up to make space for the current element.
 * - Very efficient for small data sets or nearly sorted data.
 *
 * Time Complexity: O(N^2) Average/Worst, O(N) Best.
 * Space Complexity: O(1).
 * Stability: Stable.
 */

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    insertionSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}