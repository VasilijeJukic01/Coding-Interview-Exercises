class Solution {
public:
    // {x, event, yStart, yEnd}
    using event = array<int, 4>;

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();

        long long actualArea = 0;
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;
        
        for (auto& r : rectangles) {
            actualArea += (long long)(r[2] - r[0]) * (r[3] - r[1]);
            minX = min(minX, r[0]);
            minY = min(minY, r[1]);
            maxX = max(maxX, r[2]);
            maxY = max(maxY, r[3]);
        }
        
        // Gap check
        long long expectedArea = (long long)(maxX - minX) * (maxY - minY);
        if (actualArea != expectedArea) return false;

        vector<event> events(2 * n);
        for (int i = 0, w = 0; i < n; i++, w += 2) {
            int x = rectangles[i][0], y = rectangles[i][1];
            int a = rectangles[i][2], b = rectangles[i][3];
            events[w] = {x, 1, y, b};
            events[w + 1] = {a, 0, y, b}; 
        }

        sort(events.begin(), events.end());

        multiset<array<int, 2>> ms;
        for (auto& e : events) {
            auto [x, event, yStart, yEnd] = e;

            if (event == 1) {
                auto it = ms.lower_bound({yStart, yEnd});
                
                // Check above
                if (it != ms.end() && (*it)[0] < yEnd) {
                    return false; 
                }
                // Check below
                if (it != ms.begin()) {
                    auto prevIt = prev(it);
                    if ((*prevIt)[1] > yStart) {
                        return false;
                    }
                }

                ms.insert({yStart, yEnd});
            }
            else if (event == 0) {
                ms.erase(ms.find({yStart, yEnd}));
            }
        }

        return true;
    }
};