class Solution {
public:
    double angleClock(int hour, int minutes) {
        double PI = acos(-1);

        double h = ((hour % 12) * 30 + minutes * 0.5) * PI / 180;
        double m = (minutes * 6) * PI / 180;

        double uv = cos(h) * cos(m) + sin(h) * sin(m);

        return acos(uv) * 180 / PI;
    }
};