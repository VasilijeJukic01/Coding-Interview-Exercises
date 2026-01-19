class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int best = 0;

        // {fruit, amount}
        unordered_map<int, int> map;

        int left = 0;
        for (int right = 0; right < fruits.size(); right++) {
            map[fruits[right]]++;
            while (map.size() == 3) {
                map[fruits[left]]--;
                if (map[fruits[left]] == 0) {
                    map.erase(fruits[left]);
                }
                left++;
            }
            best = max(best, right - left + 1);
        }

        return best;
    }
};