/*
* Heap Sort
 *
 * Logic:
 * 1. Build a Max Heap from the input data.
 * 2. At this point, the largest item is stored at the root of the heap.
 *    Replace it with the last item of the heap followed by reducing the size of heap by 1.
 * 3. Heapify the root of the tree.
 * 4. Repeat until heap size > 1.
 *
 * Time Complexity: O(N log N).
 * Space Complexity: O(1) (In-place).
 * Stability: Unstable.
 */

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}