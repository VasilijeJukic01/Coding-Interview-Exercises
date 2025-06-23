#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using Point = vector<int>;
Point pivot;

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
 * Calculates the squared Euclidean distance between two points.
 * Used as a tie-breaker for sorting collinear points in Graham Scan.
 */
long long distSq(Point p1, Point p2) {
    long long dx = p1[0] - p2[0];
    long long dy = p1[1] - p2[1];
	
    return dx * dx + dy * dy;
}

/**
 * The algorithm works by:
 * 1. Finding a pivot point (the one with the lowest y, then lowest x).
 * 2. Sorting all other points based on the polar angle they make with the pivot.
 * 3. Building the hull by iterating through sorted points and using a stack to discard points that create a right turn.
 */
vector<Point> grahamScan(vector<Point> points) {
    int n = points.size();
    if (n < 3) return {};

    // Pivot
    int pivotIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i][0] < points[pivotIndex][0] || (points[i][0] == points[pivotIndex][0] && points[i][1] < points[pivotIndex][1])) {
            pivotIndex = i;
        }
    }

    swap(points[0], points[pivotIndex]);
    pivot = points[0];

    // Sort by polar angle
    sort(points.begin() + 1, points.end(), [] (Point p1, Point p2) {
        long long orientation = crossProduct(pivot, p1, p2);
        // If points are collinear, the one closer to the pivot comes first
        if (orientation == 0) {
            return distSq(pivot, p1) < distSq(pivot, p2);
        }
        // Otherwise, sort by counter-clockwise
        return orientation > 0;
    });

    // Building the hull
    vector<Point> hull;
    hull.push_back(points[0]);
    
    // Remove collinear points that are closer to the pivot.
    vector<Point> uniqueAnglePoints;
    uniqueAnglePoints.push_back(points[0]);
    for(int i = 1; i < n; i++) {
        while(i < n - 1 && crossProduct(pivot, points[i], points[i+1]) == 0) {
            i++;
        }
        uniqueAnglePoints.push_back(points[i]);
    }
    
    if (uniqueAnglePoints.size() < 3) return {};

    hull.push_back(uniqueAnglePoints[1]);

    for (int i = 2; i < uniqueAnglePoints.size(); i++) {
        while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull.back(), uniqueAnglePoints[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(uniqueAnglePoints[i]);
    }

    return hull;
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

    vector<Point> convexHull = grahamScan(points);
    printHull(convexHull);

    return 0;
}
