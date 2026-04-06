class Solution {
public:
    bool judgeCircle(string moves) {
        int xDist = 0;
        int yDist = 0;

        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'U') yDist--;
            else if (moves[i] == 'D') yDist++;
            else if (moves[i] == 'L') xDist--;
            else if (moves[i] == 'R') xDist++;
        }

        return xDist == 0 && yDist == 0;
    }
};