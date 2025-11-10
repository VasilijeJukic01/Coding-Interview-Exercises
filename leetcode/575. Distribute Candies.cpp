class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;

        for (int i = 0; i < candyType.size(); i++) {
            s.insert(candyType[i]);
        }

        int cap = candyType.size() / 2;

        return s.size() < cap ? s.size() : cap;
    }
};