class Solution {
public:
    int dist(vector<int>& a, vector<int>& b) {
        int dx = b[0] - a[0];
        int dy = b[1] - a[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> d = {
            dist(p1, p2),
            dist(p1, p3),
            dist(p1, p4),
            dist(p2, p3),
            dist(p2, p4),
            dist(p3, p4)
        };

        sort(d.begin(), d.end());

        bool sideCheck = d[0] == d[1] && d[1] == d[2] && d[2] == d[3];
        bool diagonalCheck = d[4] == d[5] && d[4] == 2 * d[0];

        return d[0] > 0 && sideCheck && diagonalCheck;
    }
};