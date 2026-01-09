class Solution {
public:
    // {position, speed}
    using p = array<int, 2>;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<p> v;
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end());

        stack<double> st;
        for (int i = n - 1; i >= 0; i--) {
            double t = (double)(target - v[i][0]) / v[i][1];
            if (st.empty() || t > st.top()) st.push(t);
        }

        return st.size();
    }
};