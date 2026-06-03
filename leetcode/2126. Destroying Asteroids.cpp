class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long total = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > total) return false;
            total += asteroids[i];
        }

        return true;
    }
};