class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            int carry = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;

            if (carry == 0) return digits;
        }
        
        digits.insert(digits.begin(), 1);

        return digits;
    }
};