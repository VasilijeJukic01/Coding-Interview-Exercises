class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s1, s2;
        vector<int> leftSmallest(n, -1);
        vector<int> rightSmallest(n, n);

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            while (!s1.empty() && heights[i] <= heights[s1.top()]) {
                s1.pop();
            }
            while (!s2.empty() && heights[j] <= heights[s2.top()]) {
                s2.pop();
            }

            if (!s1.empty()) leftSmallest[i] = s1.top();
            if (!s2.empty()) rightSmallest[j] = s2.top();

            s1.push(i);
            s2.push(j);
        }

        int surface = 0;
        for (int i = 0; i < n; i++) {
            int wid = rightSmallest[i] - leftSmallest[i] - 1;

            surface = max(surface, wid * heights[i]);
        }

        return surface;
    }
};