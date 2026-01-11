/*
 * Timsort
 *
 * Logic:
 * - A hybrid of Merge Sort and Insertion Sort.
 * - Divides the array into small blocks known as Runs (typically size 32 or 64).
 * - Sorts these Runs using Insertion Sort.
 * - Merges the sorted Runs using the Merge function (from Merge Sort).
 * - Highly efficient for real-world data which often contains ordered subsequences.
 *
 * Time Complexity: O(N log N) Average/Worst, O(N) Best.
 * Space Complexity: O(N).
 * Stability: Stable.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RUN = 32;

// Standard Insertion Sort for the specific range [left, right]
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;

    vector<int> leftArr(len1);
    vector<int> rightArr(len2);

    for (int i = 0; i < len1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = leftArr[i];
        i++; k++;
    }

    while (j < len2) {
        arr[k] = rightArr[j];
        j++; k++;
    }
}

void timSort(vector<int>& arr) {
    int n = arr.size();

    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i += RUN) {
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));
    }

    // Merging from size RUN (32)
    // arr[0..31] is sorted, arr[32..63] is sorted... merge them
    // Then merge size 64, 128, etc
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            // Find ending point of left sub array
            // mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            // Only merge if mid < right (if there is a right subarray)
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 21, 7, 23, 19, 10, 2, 15, 33, 1, 6, 8, 44, 3, 30};
    
    timSort(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}