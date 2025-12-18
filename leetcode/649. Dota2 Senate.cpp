class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiantQ;
        queue<int> direQ;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiantQ.push(i);
            else direQ.push(i);
        }

        while (!radiantQ.empty() && !direQ.empty()) {
            int rIndex = radiantQ.front();
            int dIndex = direQ.front();

            direQ.pop();
            radiantQ.pop();

            if (rIndex < dIndex) radiantQ.push(rIndex + n);
            else direQ.push(dIndex + n);
        }

        if (radiantQ.empty()) return "Dire";
        return "Radiant";
    }
};