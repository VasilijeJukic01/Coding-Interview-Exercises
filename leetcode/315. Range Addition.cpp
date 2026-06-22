#include <iostream>
#include <vector>

using namespace std;

void rangeAddition(vector<int> &arr, vector<vector<int>>& updates) {
    vector<int> diffs(arr.size());
    for (auto& update : updates) {
        int left = update[0], right = update[1];
        int val = update[2];
        
        diffs[left] += val;
        diffs[right + 1] -= val;
    }
    
    int pSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        pSum += diffs[i];
        arr[i] = pSum;
    }
}

int main() {
    int n = 5;
    vector<vector<int>> updates = {
        {1,3,2}, {2,4,3}, {0,2,-2}
    };
    
    vector<int> arr(n);
    rangeAddition(arr, updates);
    
    for (auto& x : arr) cout << x << " ";
    
    return 0;
}