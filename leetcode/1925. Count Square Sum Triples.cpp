class Solution {
public:
    int countTriples(int n) {
        int total = 0;
        set<int> s;

        for (int i = 1; i <= n; i++) {
            s.insert(i * i);
        }

        for (int i = 1; i <= n; i++) {
            int a = i * i;
            for (int j = 1; j <= n; j++) {
                int b = j * j;
                if (s.find(a + b) != s.end()) total++;
            }
        }

        return total;
    }
};