class Solution {
public:
    bool check(long long aMask, long long bMask, int x) {
        return (aMask & (1LL << x)) && (bMask & (1LL << x));
    }

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        long long aMask = 0, bMask = 0;
        long long common = 0;

        vector<int> C;
        int count = 0;
        for (int i = 0; i < n; i++) {
            aMask |= (1LL << A[i]);
            bMask |= (1LL << B[i]);

            bool checkA = check(aMask, bMask, A[i]);
            bool checkB = check(aMask, bMask, B[i]);
            if (checkA && ((common & (1LL << A[i])) == 0)) {
                common |= (1LL << A[i]);
                count++;
            }
            if (checkB && ((common & (1LL << B[i])) == 0)) {
                common |= (1LL << B[i]);
                count++;
            }

            C.push_back(count);
        }

        return C;
    }
};