class Solution {
    double r, xc, yc;
public:
    Solution(double radius, double x_center, double y_center) {
        this->r = radius;
        this->xc = x_center;
        this->yc = y_center;
    }
    
    vector<double> randPoint() {
        double theta = 2 * M_PI * (double) rand() / RAND_MAX;
        double d = r * sqrt((double) rand() / RAND_MAX);
        
        return {xc + d * cos(theta), yc + d * sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */