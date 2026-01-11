/*
* Bucket Sort
 *
 * Logic:
 * - Distribute elements into several buckets based on a hashing formula.
 * - Sort each bucket individually (often using Insertion Sort or std::sort).
 * - Concatenate the sorted buckets.
 * - Ideally suited for uniformly distributed floating-point data.
 *
 * Time Complexity: O(N + K) Average, O(N^2) Worst (if all elements fall into one bucket).
 * Space Complexity: O(N).
 * Stability: Stable (if the underlying bucket sort is stable).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        // Formula depends on range. For [0, 1), index = n * arr[i]
        int bucketIndex = n * arr[i];

        // Safety check if value is exactly 1.0
        if (bucketIndex >= n) bucketIndex = n - 1;

        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);

    cout << "Sorted array: ";
    for (float x : arr) cout << x << " ";
    cout << endl;
    return 0;
}