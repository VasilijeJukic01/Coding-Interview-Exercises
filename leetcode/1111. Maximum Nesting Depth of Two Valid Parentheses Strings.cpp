class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        vector<int> result(n);
        int depthA = 0, depthB = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                if (!flag) depthA++;
                else depthB++;
            }
            else {
                if (!flag) depthA--;
                else depthB--;
            }

            if (depthA > depthB + 1) {
                depthA--;
                flag = !flag;
                depthB++;
            }
            else if (depthB > depthA + 1) {
                depthB--;
                flag = !flag;
                depthA++;
            }
            result[i] = flag;
        }
        
        return result;
    }
};