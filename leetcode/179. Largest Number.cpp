class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [] (const int& x, const int& y) {
            return to_string(x) + to_string(y) >  to_string(y) + to_string(x);
        });

        stringstream ss;
        for (int i = 0; i < nums.size(); i++) {
            ss << to_string(nums[i]);
        }

        int i = 0;
        string s = ss.str();
        while (i < s.size() - 1 && s[i] == '0') {
            i++;
        }

        return s.substr(i);
    }
};