/*
* Radix Sort
 *
 * Logic:
 * - Sorts numbers digit by digit from least significant digit to most significant digit.
 * - Uses Counting Sort as a subroutine for each digit.
 *
 * Time Complexity: O(NK) where K is number of digits.
 * Space Complexity: O(N + Base).
 * Stability: Stable.
 */

#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Counting sort for a specific digit represented by exp (1, 10, 100...)
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    // Find the maximum number to know number of digits
    int m = getMax(arr);

    // Do counting sort for every digit.
    // Instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}