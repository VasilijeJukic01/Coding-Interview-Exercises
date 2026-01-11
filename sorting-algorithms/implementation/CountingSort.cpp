/*
* Counting Sort
 *
 * Logic:
 * - Works by counting the number of objects having distinct key values.
 * - Then doing some arithmetic to calculate the position of each object in the output sequence.
 * - Efficient when the range of input data (k) is not significantly greater than the number of objects (n).
 *
 * Time Complexity: O(N + K).
 * Space Complexity: O(K).
 * Stability: Stable.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum element to determine range
    int maxVal = *max_element(arr.begin(), arr.end());

    vector<int> count(maxVal + 1, 0);

    // Store count of each character
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    // Store cumulative count
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Iterate backwards to preserve stability
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}