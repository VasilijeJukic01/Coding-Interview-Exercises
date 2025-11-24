class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        
        vector<string> result;

        string curr = to_string(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) continue;
            else {
                if (nums[i - 1] != stoi(curr)) {
                    curr += "->" + to_string(nums[i - 1]);
                }
                result.push_back(curr);
                curr = to_string(nums[i]);
            }
        }
        if (nums[nums.size() - 1] != stoi(curr)) {
            curr += "->" + to_string(nums[nums.size() - 1]);
        }
        result.push_back(curr);

        return result;
    }
};