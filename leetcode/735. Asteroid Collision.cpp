class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> dq;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) dq.push_back(asteroids[i]);
            else {
                int diff = -1;
                while (!dq.empty() && dq.back() > 0 && dq.back() - abs(asteroids[i]) <= 0) {
                    diff = dq.back() - abs(asteroids[i]);
                    dq.pop_back();
                    if (diff == 0) break;
                }
                if (diff < 0 && (dq.empty() || dq.back() < 0)) {
                    dq.push_back(asteroids[i]);
                }
            }
        }

        vector<int> result;
        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }

        return result;
    }
};