/*
You are simulating a 1D battle line for a robot fighting game.
- The input is an array robots.
- The absolute value represents the robot's power level.
- The sign represents direction: Positive integers move Right (→), Negative integers move Left (←).

The Rules:
1. Robots moving in the same direction never meet.
2. If a Right-moving robot meets a Left-moving robot, they fight.
3. The robot with the smaller power level is destroyed.
4. If both have the same power level, both are destroyed.
5. Robots moving away from each other (Left then Right) do not fight.

Return an array containing the power levels of the surviving robots.

Input: [-10, 5, 8, -6, -2, 4]
Output: [-10, 5, 8, 4]
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int>& robots) {
    vector<int> st;

    for (int robot : robots) {
        bool destroyed = false;
        while (!st.empty() && st.back() > 0 && robot < 0) {
            int rightPower = st.back();
            int leftPower = -robot;

            if (rightPower < leftPower) {
                st.pop_back();
            }
            else if (rightPower == leftPower) {
                st.pop_back();
                destroyed = true;
                break;
            }
            else {
                destroyed = true;
                break;
            }
        }
        if (!destroyed) st.push_back(robot);
    }

    return st;
}

int main() {
    vector<int> robots = {-10, 5, 8, -6, -2, 4};

    vector<int> v = solve(robots);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}