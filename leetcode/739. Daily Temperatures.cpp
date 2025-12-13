class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return result;
    }
};