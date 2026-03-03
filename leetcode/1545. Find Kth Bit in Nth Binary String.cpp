class Solution {
public:
    string reverse(string curr) {
        for (int i = 0, j = curr.size() - 1; i < j; i++, j--) {
            swap(curr[i], curr[j]);
        }
        return curr;
    }

    string invert(string curr) {
        for (int i = 0; i < curr.size(); i++) {
            int bit = curr[i] - '0';
            curr[i] = (1 - bit) + '0';
        }
        return curr;
    }

    char findKthBit(int n, int k) {
        string curr = "0";

        for (int i = 1; i < n; i++) {
            curr += "1" + reverse(invert(curr));
        }

        return curr[k - 1];
    }
};