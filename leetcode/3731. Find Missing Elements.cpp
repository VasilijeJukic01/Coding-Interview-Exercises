class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        vector<int> map(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        int left = 0, right = 100;
        while (map[left] == 0) left++;
        while (map[right] == 0) right--;

        for (int i = left; i <= right; i++) {
            if (map[i] == 0) result.push_back(i);
        }

        return result;
    }
};