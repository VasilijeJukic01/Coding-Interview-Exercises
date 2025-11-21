class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> components;
        long p = 1;

        while (n) {
            int digit = n % 10;
            if (digit != 0) {
                components.push_back(digit * p);
            }
            p *= 10;
            n /= 10;
        }

        for (int i = 0, j = components.size() - 1; i < j; i++, j--) {
            components[i] ^= components[j];
            components[j] ^= components[i];
            components[i] ^= components[j];
        }

        return components;
    }
};