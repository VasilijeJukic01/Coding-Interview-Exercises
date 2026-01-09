class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int maxLen = 0;
        for (auto& item : s) {
            if (s.find(item - 1) == s.end()) {
                int j = item;
                int currLen = 0;
                while (s.find(j) != s.end()) {
                    currLen++;
                    j++;
                }
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};