class Solution {
public:
    bool isPrime(int n) {
        if (n == 0 || n == 1) return false;
        
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> map(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        for (int i = 0; i < 101; i++) {
            if (isPrime(map[i])) return true;
        }

        return false;
    }
};