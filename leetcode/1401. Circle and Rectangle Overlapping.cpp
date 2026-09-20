class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) {
            return true;
        }

        int r = radius;
        // Upper & Bottom
        for (int x = x1; x <= x2; x++) {
            int yU = y2, yB = y1;

            int dx = x - xCenter;
            int dyU = yU - yCenter;
            int dyB = yB - yCenter;

            if (dx * dx + dyU * dyU <= r * r) return true;
            if (dx * dx + dyB * dyB <= r * r) return true;
        }
        // Left & Right
        for (int y = y1; y <= y2; y++) {
            int xL = x1, xR = x2;

            int dy = y - yCenter;
            int dxL = xL - xCenter;
            int dxR = xR - xCenter;

            if (dxL * dxL + dy * dy <= r * r) return true;
            if (dxR * dxR + dy * dy <= r * r) return true;
        }
        
        return false;
    }
};