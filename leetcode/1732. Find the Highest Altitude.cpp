class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxima = 0;
        
        int total = 0;
        for (int i = 0; i < gain.size(); i++) {
            total += gain[i];
            maxima = max(maxima, total);
        }

        return maxima;
    }
};