/*
In the sprawling, velvet-draped halls of the Grand Feline Estate, a pack of cunning cats has turned the mansion’s 
floor into their personal playground. This floor isn’t just any surface. It’s a meticulously tiled grid, laid out 
with m rows running north to south and n columns stretching east to west, each square a plush patch of paradise for 
a cat’s paws. Well, most of them, anyway. The game begins when the estate’s caretaker, a whimsical woman with a love 
for feline antics, gathers her furry friends for a challenge. She’s hidden a stash of the most delectable cat treats 
at a spot that’s tricky to reach, and the cats, with their sharp instincts, sense it’s tucked away where the grid’s 
edges meet in shadow. Their mission is a playful yet perilous one: starting from a sun-warmed tile where the day’s 
first rays spill across the floor, they must weave their way to that treat-laden nook. These aren’t reckless kittens, 
though, they’re clever felines bound by a strict rulebook. At any moment, a cat can only leap one tile southward, 
chasing a whisper of wind, or pounce one tile eastward, just steady south-or-east steps.

But here’s the twist that tangles their tails: the caretaker, with a mischievous grin, has scattered a few "cat traps" 
across the grid—tiles laced with a scent so foul (think sour milk or wet dog fur) that no self-respecting cat would 
dare set paw on them. These traps don’t just complicate the journey; they block entire tiles, forcing the cats to 
detour around them. The estate’s owner, a riddle-loving cat whisperer, challenges her guests to figure out how many 
unique paths these agile kitties can take to reach the treats, avoiding every trap along the way. Each path is a 
one-of-a-kind sequence of hops and pounces, a feline saga of evasion and elegance. The cats still need enough 
southward leaps to span the grid’s height and enough eastward pounces to cross its width, but now they must dodge 
those pesky traps, imagining a tabby muttering, "East past the sofa, south by the vase—but ugh, that trap by the 
window means I’ll need a new plan!"

The grid isn’t entirely a minefield—most tiles are safe, plush havens—but the traps (specified in the input as a 
list of coordinates) add a layer of chaos. The owner promises the total number of possible paths won’t exceed 2 * 10^9, 
a mystical cap on the cats’ cunning, and the mansion’s kittens still perch along the edges, meowing encouragement as 
their elders navigate this tricky terrain. Your task is to deduce how many unique journeys these cats can take across 
the m x n grid, starting where the morning glow begins and ending where the treats await, all while steering clear of 
the caretaker’s traps.

Input Format:
m: number of rows
n: number of columns
traps: a list of [row, col] coordinates where traps are located (0-based indexing)

Example 1:
Input: m = 2, n = 4, traps = []
Output: 4
Explanation: No traps! From the sunlit start to the treat hoard, it’s 1 hop south and 3 pounces east:
1. EEE -> S
2. EES -> E
3. ESE -> E
4. SEE -> E
Four trap-free feline odysseys!

Example 2:
Input: m = 3, n = 7, traps = [[1, 2], [2, 1]]
Output: 10
Explanation: In this case, the grid is 3 rows by 7 columns, and two traps are located at the coordinates (1, 2) and 
(2, 1). These traps are off-limits for the cats, and they must find alternative paths to reach the treats.
From the top-left corner, the cats need to move 2 tiles south and 6 tiles east to reach the bottom-right corner, 
but they must avoid stepping on the traps. By avoiding the traps, there are exactly 10 unique ways.
*/

#include <iostream>
#include <vector>

using namespace std;

int findPaths(int m, int n, vector<pair<int, int>> traps) {
   vector<vector<int>> dp(m, vector<int>(n, 0));
   
   for (auto trap : traps)
        dp[trap.first][trap.second] = -1;
   
    if (dp[0][0] != -1) dp[0][0] = 1;

    for (int j = 1; j < n; j++)
        if (dp[0][j] != -1 && dp[0][j-1] > 0) 
			dp[0][j] = dp[0][j-1];

    for (int i = 1; i < m; i++)
        if (dp[i][0] != -1 && dp[i-1][0] > 0) 
			dp[i][0] = dp[i-1][0];
   
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (dp[i][j] == -1) continue;
            if (dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
            if (dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
        }
    }

    if (dp[m-1][n-1] > 0) return dp[m-1][n-1];
    return 0;
}

int main() {
    int m = 3, n = 7;
    vector<pair<int, int>> traps = {{1, 2}, {2, 1}};
    
    cout << findPaths(m, n, traps);

    return 0;
}