#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using Point = vector<int>;

void printHull(vector<Point> hull) {
    if (hull.empty()) {
        cout << "  (Empty Hull - fewer than 3 points)" << endl;
        return;
    }
	
    for (Point p : hull) {
        cout << "  [" << p[0] << ", " << p[1] << "]" << endl;
    }
	
    cout << endl;
}

/**
 * Determines the orientation of the ordered triplet (p1, p2, p3).
 *
 * @param p1 The origin point of the vectors.
 * @param p2 The end point of the first vector.
 * @param p3 The end point of the second vector.
 *
 * @return > 0 if p1-p2-p3 is a left turn (counter-clockwise).
 * @return < 0 if p1-p2-p3 is a right turn (clockwise).
 * @return = 0 if p1, p2, and p3 are collinear.
 */
long long crossProduct(Point p1, Point p2, Point p3) {
    long long x1 = p1[0], y1 = p1[1];
    long long x2 = p2[0], y2 = p2[1];
    long long x3 = p3[0], y3 = p3[1];
	
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}
/**
 * The algorithm works by first sorting the points by x, then y.
 * Then, it constructs the lower and upper hulls of the points in a single pass.
 */
vector<Point> monotoneChain(vector<Point> points) {
    int n = points.size();
	
    if (n < 3) return {};

    // Sorting
    sort(points.begin(), points.end());

    vector<Point> lowerHull;
    vector<Point> upperHull;

    // Buidling Hulls
    for (auto p : points) {
        // Lower Hull
        while (lowerHull.size() >= 2 && crossProduct(lowerHull[lowerHull.size() - 2], lowerHull.back(), p) <= 0) {
            lowerHull.pop_back();
        }
        lowerHull.push_back(p);

        // Upper Hull
        while (upperHull.size() >= 2 && crossProduct(upperHull[upperHull.size() - 2], upperHull.back(), p) >= 0) {
            upperHull.pop_back();
        }
        upperHull.push_back(p);
    }

    // Merge
    for (int i = upperHull.size() - 2; i > 0; i--) {
        lowerHull.push_back(upperHull[i]);
    }

    return lowerHull;
}

int main() {
    vector<Point> points = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };
	
    // Hull: [0,0], [3,1], [4,4], [0,3]

    cout << "Input points:" << endl;
    for(auto p : points) cout << "  [" << p[0] << ", " << p[1] << "]";
	
    cout << endl << "Convex Hull: " << endl;

    vector<Point> convexHull = monotoneChain(points);
    printHull(convexHull);

    return 0;
}
