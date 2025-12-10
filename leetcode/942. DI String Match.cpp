class Solution {
public:
    vector<int> diStringMatch(string s) {
        int left = 0;
        int right = s.size();

        vector<int> result;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') result.push_back(left++);
            else result.push_back(right--);
        }

        result.push_back(left);

        return result;
    }
};