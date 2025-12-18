/*
Deep within the bioluminescent currents of the Sapphire River, the annual migration of the Neon-Fin Salmon has begun.
These fish are unique because they swim in a perfectly spaced, single-file line that stretches for miles. Each salmon 
carries a specific amount of Bio-Charge (measured in units) which they use to power the spawning grounds upstream.
You are a marine biologist stationed at a narrow underwater observation pipe. Your high-speed camera has a Fixed 
Viewport that can only capture exactly W salmon at any given microsecond.
As the line of fish swims past your station, the viewport constantly updates. First, you see salmon 1 through W.
A moment later, the first salmon leaves the frame on the left, and the (W+1)-th salmon enters the frame from the right.
This continues until the very last salmon in the migration has passed through the right side of your frame.

For your research, you need to document the Apex Charge for every single frame captured. The Apex Charge is the highest 
Bio-Charge value present among the W salmon currently visible in the viewport.

Process the entire migration sequence and produce a "Chronological Apex Log", a list of the maximum Bio-Charge values 
seen in the viewport as the line of fish moves past.

Example:
The Migration Line (Bio-Charge): [8, 14, 1, 25, 25, 19, 30, 10, 12]
Viewport Width: 3

The Final Apex Log: [14, 25, 25, 25, 30, 30, 30]

The Sapphire River flows fast! Your analysis must be completed in Linear Time O(N). If your algorithm takes too long, 
the camera's buffer will overflow and the data will be lost.
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> solve(vector<int>& bioCharge, int w) {
    vector<int> apexLog;
    deque<int> dq;

    for (int i = 0; i < bioCharge.size(); i++) {
        while (!dq.empty() && bioCharge[i] >= bioCharge[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (dq.back() - dq.front() >= w) {
            dq.pop_front();
        }

        if (i >= w - 1) apexLog.push_back(bioCharge[dq.front()]);

    }

    return apexLog;
}

int main() {
    vector<int> bioCharge = {8, 14, 1, 25, 25, 19, 30, 10, 12};

    vector<int> apexLog = solve(bioCharge , 3);

    for (int i = 0; i < apexLog.size(); i++) {
        cout << apexLog[i] << " ";
    }

    return 0;
}