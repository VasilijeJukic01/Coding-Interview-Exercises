class Solution {
public:
    int divideAndConquer(string& s, int k, int start, int end) {
        if (start > end || end - start + 1 < k) return 0;

        vector<int> map(26, 0);
        for (int i = start; i <= end; i++) {
            map[s[i] - 'a']++;
        }

        for (int i = start; i <= end; i++) {
            if (map[s[i] - 'a'] < k) {
                int left = divideAndConquer(s, k, start, i - 1);
                int right = divideAndConquer(s, k, i + 1, end);
                return max(left, right);
            }
        }

        return end - start + 1;
    }

    int longestSubstring(string s, int k) {
        return divideAndConquer(s, k, 0, s.size() - 1);
    }
};