class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int best = -1;
		
        for (int i = arr.size() - 1; i >= 0; i--) {
            int candidate = arr[i];
            arr[i] = best;
            best = max(best, candidate);
        }

        return arr;
    }
};