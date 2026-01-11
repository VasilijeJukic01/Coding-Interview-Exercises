/*
* Quick Sort
 *
 * Logic:
 * - Divide and Conquer algorithm.
 * - Picks a pivot element and partitions the array such that elements smaller than pivot are on the left,
 *   and larger on the right.
 * - Recursively sorts partitions.
 *
 * Time Complexity: O(N log N) Average, O(N^2) Worst (bad pivot selection).
 * Space Complexity: O(log N) stack space.
 * Stability: Unstable.
 */

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    return 0;
}