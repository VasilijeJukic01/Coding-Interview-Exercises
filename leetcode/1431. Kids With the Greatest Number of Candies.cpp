class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;

        int best = 0;
        for_each(candies.begin(), candies.end(), [&best](int candy) {
            best = max(best, candy);
        });

        for_each(candies.begin(), candies.end(), [&best, &extraCandies, &result](int candy) {
            result.push_back(candy + extraCandies >= best);
        });

        return result;
    }
};