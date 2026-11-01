class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int minima = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            minima = min(minima, nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            moves += (nums[i] - minima);
        } 

        return moves;
    }
};