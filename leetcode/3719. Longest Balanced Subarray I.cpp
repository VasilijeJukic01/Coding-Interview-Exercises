class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> s;

        int odd = 0, even = 0;
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (s.find(nums[j]) == s.end()) {
                    if (nums[j] % 2 == 0) even++;
                    else odd++;
                    s.insert(nums[j]);
                }
                if (odd == even) {
                    longest = max(longest, j - i + 1);
                }
            }
            s.clear();
            odd = 0, even = 0;
        }

        return longest;
    }
};