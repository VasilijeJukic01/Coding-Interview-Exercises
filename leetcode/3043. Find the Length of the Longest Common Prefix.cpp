class Solution {
public:
    int size(int num) {
        int size = 0;
        while (num) {
            num /= 10;
            size++;
        }
        return size;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;

        for (int num : arr1) {
            while (num) {
                s.insert(num);
                num /= 10;
            }
        }

        int maxPrefix = 0;
        for (int num : arr2) {
            while (num) {
                if (s.find(num) != s.end()) {
                    maxPrefix = max(maxPrefix, size(num));
                    break;
                }
                num /= 10;
            }
        }

        return maxPrefix;
    }
};