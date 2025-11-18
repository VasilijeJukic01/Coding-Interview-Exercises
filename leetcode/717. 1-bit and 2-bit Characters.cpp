class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = -1;

        for (int i = 0; i < bits.size(); i++) {
            if (bits[i] == 1) i++;
            else if (bits[i] == 0) index = i;
        }
        if (index == bits.size() - 1) return true;
        return false;
    }
};