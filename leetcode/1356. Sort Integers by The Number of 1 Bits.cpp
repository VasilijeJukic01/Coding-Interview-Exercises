class Solution {
public:
    static int countSetBits(int n) {
        int counter = 0;
        while (n) {
            n = n & (n - 1);
            counter++;
        }

        return counter;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), 
            [](const int& x, const int& y) {
            int xBits = countSetBits(x);
            int yBits = countSetBits(y);

            if (xBits != yBits) return xBits < yBits;
            return x < y;
        });

        return arr;
    }
};