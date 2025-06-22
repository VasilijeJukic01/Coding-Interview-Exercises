/*
You are the assistant coach of a football team preparing for a crucial match. During a set-piece (e.g., a corner kick or 
free kick), your team needs to form a tactical enclosure on the field to maximize control over a specific area. The players 
are positioned at various coordinates on the 2D football field, represented as points (x, y) in meters, where (0, 0) is the 
bottom-left corner of the field. To create an effective enclosure, the team wants to identify the smallest convex polygon 
that includes all players' positions, ensuring no player is left outside the formation.

This convex polygon represents the outermost players who will form a defensive or offensive perimeter, allowing the team to 
control the enclosed area. For example, players at the edges of the formation might be wingers or fullbacks, while those inside 
could be midfielders or strikers. Your task is to determine the coordinates of the players who form the vertices of this tactical 
enclosure in counterclockwise order, starting from the player with the smallest x-coordinate (and smallest y-coordinate in case 
of a tie). This order helps the team communicate the formation clearly, starting from the leftmost player.

The field is a standard-sized football pitch, but for simplicity, we assume all coordinates are integers. If there are fewer 
than three players, a valid enclosure cannot be formed, and you should return an empty list.

Write a function to compute the vertices of the tactical enclosure given the list of player positions. The output will help the 
team visualize their formation and assign roles to the perimeter players.

Input:
- players: A list of lists [[x1, y1], [x2, y2], ..., [xn, yn]], where each [xi, yi] represents the position of a player on the field 
in meters.
1 <= players.length <= 10^4
0 <= xi, yi <= 100 (representing a simplified 100m x 100m field)
All player positions are unique (no two players at the same spot).

Output:
A list of lists [[x1, y1], [x2, y2], ...] representing the positions of the players who form the vertices of the tactical enclosure 
in counterclockwise order, starting from the player with the smallest x-coordinate (and smallest y-coordinate if there’s a tie).
If fewer than 3 players are provided, return an empty list, as a valid enclosure cannot be formed.

Example:
Input: players = [[10,20],[10,40],[30,20],[20,30]]
Output: [[10,20],[10,40],[30,20]]
Explanation: The players at [10,20], [10,40], and [30,20] form a triangular enclosure that includes the player at [20,30] (midfielder).
The vertices are listed in counterclockwise order starting from [10,20].
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int crossProduct(vector<int> a, vector<int> b, vector<int> c) {
    int x1 = a[0], y1 = a[1];
    int x2 = b[0], y2 = b[1];
    int x3 = c[0], y3 = c[1];
    
    return (y3-y2) * (x2-x1) - (y2-y1) * (x3-x2);
}

vector<vector<int>> solve(vector<vector<int>> players) {
    sort(players.begin(), players.end(), [] (auto a, auto b) {
       return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; 
    });
    
    vector<vector<int>> lower, upper;
    
    for (vector<int> p : players) {
        // Lower Hull
        while (lower.size() >= 2 && crossProduct(lower[lower.size()-2], lower.back(), p) < 0) {
            lower.pop_back();
        }
        // Upper Hull
        while (upper.size() >= 2 && crossProduct(upper[upper.size()-2], upper.back(), p) > 0) {
            upper.pop_back();
        }
        
        lower.push_back(p);
        upper.push_back(p);
    }
    
    vector<vector<int>> result = lower;
    
    for (int i = upper.size() - 2; i > 0; i--) {
        result.push_back(upper[i]);
    }
    
    return result;
}

int main() {
	vector<vector<int>> p = {
		{1, 20},
		{7, 20},
		{10, 23},
		{14, 42},
		{21, 1},
		{22, 10},
		{23, 2},
		{23, 43},
		{29, 37},
		{35, 39},
		{38, 18},
		{38, 28}
	};
    
    vector<vector<int>> hull = solve(p);
    
    for (int i = 0; i < hull.size(); i++) {
        for (int j = 0; j < hull[0].size(); j++)
            cout << hull[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
