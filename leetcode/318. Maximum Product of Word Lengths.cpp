class Solution {
public:
    int maxProduct(vector<string>& words) {
        // {mask, maxLen}
        unordered_map<int, int> masks;

        for (auto& word : words) {
            int mask = 0;
            for (int i = 0; i < word.size(); i++) {
                mask |= 1 << (word[i] - 'a');
            }
            int len = word.size();
            masks[mask] = max(masks[mask], len);
        }

        int maxProd = 0;
        for (auto& [maskI, lenI] : masks) {
            for (auto& [maskJ, lenJ] : masks) {
                if (maskI & maskJ) continue;
                maxProd = max(maxProd, lenI * lenJ);
            }
        }

        return maxProd;
    }
};