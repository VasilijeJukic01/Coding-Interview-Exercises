class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<array<int, 2>> blocks;

        int ones = count(s.begin(), s.end(), '1');
        int bit = s[0] - '0', count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] - '0' == bit) count++;
            else {
                blocks.push_back({bit, count});
                bit = !bit;
                count = 1;
            }
        }
        blocks.push_back({bit, count});

        int best = ones;
        for (int i = 0; i < blocks.size(); i++) {
            bit = blocks[i][0], count = blocks[i][1];
            if (bit == 0) continue;
            if (i > 0 && i < blocks.size() - 1) {
                auto& [leftBit, leftCount] = blocks[i - 1];
                auto& [rightBit, rightCount] = blocks[i + 1];

                if (leftBit == 0 && rightBit == 0) {
                    best = max(best, ones + leftCount + rightCount);
                }
            }
        }

        return best;
    }
};