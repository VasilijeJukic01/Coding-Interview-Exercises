class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> dq;

        for (int i = 0; i < num.size(); i++) {
            while (!dq.empty() && k != 0 && num[i] - '0' < dq.back()) {
                dq.pop_back();
                k--;
            }
            dq.push_back(num[i] - '0');
        }

        while (k) {
            dq.pop_back();
            k--;
        }

        string result;
        for (int i = 0; i < dq.size(); i++) {
            result.push_back(dq[i] + '0');
        }

        int pos = 0;
        while (pos < result.size() && result[pos] == '0')
            pos++;

        result = result.substr(pos);

        if (result.empty()) return "0";
        return result;
    }
};