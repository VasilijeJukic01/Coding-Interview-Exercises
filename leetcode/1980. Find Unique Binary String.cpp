class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;

        for (int i = 0; i < nums.size(); i++) {
            int bit = 1 - (nums[i][i] - '0');
            result.push_back(bit + '0');
        }

        return result;
    }
};