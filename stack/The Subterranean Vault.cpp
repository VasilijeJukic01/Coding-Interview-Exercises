/*
You are the chief architect for a "Doomsday Prepper" company. You have scanned a cross-section of land where a client 
wants to build a single, massive rectangular bunker underground.
The scanner has returned an array of integers, bedrock_depths, representing the depth of the solid bedrock at contiguous 
1-meter intervals along the property line.

The Rules:
1. You must excavate a single rectangular room.
2. The room must be defined by a contiguous range of these 1-meter intervals.
3. The top of the room is at ground level (depth=0).
4. The floor of the room must be perfectly flat (horizontal).
5. You cannot excavate into the bedrock. Therefore, the depth of your room cannot exceed the bedrock depth of any 
specific interval included in your chosen range.
6. The goal is to maximize the Total Cross-Sectional Area of the room to store the maximum amount of supplies.

Input
bedrock_depths: An array of non-negative integers where bedrock_depths[i] is the distance from the surface to the 
rock at index i.

Output
Return the maximum possible area of the excavated room.

Example:
Input: bedrock_depths = [1, 5, 4, 5, 2]
Output: 12

You focus on the rich bedrock in the middle, from index 1 to index 3 (values 5, 4, 5).
The width is 3 meters. The depth is limited by the middle section. Area = 4 x 3 = 12.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solve(vector<int>& bedrock_depths) {
    int n = bedrock_depths.size();
    stack<int> sLeft, sRight;

    vector<int> leftLimit(n, -1);
    vector<int> rightLimit(n, n);

    for (int i = 0, j = n - 1; i < n; i++, j--) {
        while (!sLeft.empty() && bedrock_depths[i] <= bedrock_depths[sLeft.top()]) {
            sLeft.pop();
        }
        if (!sLeft.empty()) leftLimit[i] = sLeft.top();
        sLeft.push(i);

        while (!sRight.empty() && bedrock_depths[j] <= bedrock_depths[sRight.top()]) {
            sRight.pop();
        }
        if (!sRight.empty()) rightLimit[j] = sRight.top();
        sRight.push(j);
    }

    int bestVault = 0;
    for (int i = 0; i < n; i++) {
        int wid = rightLimit[i] - leftLimit[i] - 1;

        bestVault = max(bestVault, wid * bedrock_depths[i]);
    }

    return bestVault;
}

int main() {
    vector<int> site = {1, 5, 4, 5, 2};

    cout << solve(site);
    
    return 0;
}