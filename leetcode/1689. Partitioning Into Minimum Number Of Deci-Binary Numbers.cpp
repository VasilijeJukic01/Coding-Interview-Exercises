class Solution {
public:
    int minPartitions(string n) {
        int maxNum = 0;
        for (int i = 0; i < n.size(); i++) {
            maxNum = max(maxNum, n[i] - '0');
        }

        return maxNum;
    }
};