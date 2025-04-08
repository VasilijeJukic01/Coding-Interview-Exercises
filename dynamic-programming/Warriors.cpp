/*
In the mystical realm of Zhar'akhar, you are a grand wizard tasked with commanding an army of enchanted warriors to 
defend the kingdom against shadowy invaders. Each day, the magical energies of the land shift unpredictably, 
influencing both the mana required to summon a warrior into existence and the gold bounty earned when you send a 
warrior into battle to vanquish foes.

You are given an array, manaFlux, where manaFlux[i] represents the mystical energy level on the ith day: it serves as 
both the mana cost to summon a single warrior and the gold reward for sending a warrior into combat. Your goal is to 
maximize your net gain—defined as the total gold collected from battles minus the total mana expended on summoning—through 
a series of summoning and battling decisions over the days.

However, the arcane laws of Zhar'akhar impose convoluted restrictions on your actions:

- At any moment, you may control only one warrior. You must send your current warrior into battle (thus losing control 
of them) before you can summon another.
- After sending a warrior into battle on a given day, the magical energies become turbulent, requiring you to enter a 
"rest state" on the next day. During this rest state, you are forbidden from summoning a new warrior, though you may 
still send an existing warrior into combat if you have one under your command (which, of course, triggers another rest 
state the following day).
- To complicate matters, the realm's elder council has decreed that every time you summon a warrior, you must offer a 
tribute to the ancient spirits equal to the minimum manaFlux[j] value from day 0 up to the current day i (inclusive), 
paid in additional mana. This tribute is mandatory and adds to the summoning cost on day i, making the total mana cost 
manaFlux[i] + min(manaFlux[0..i]).

You may choose to do nothing on any day, neither summoning nor sending a warrior into battle or perform one of the 
allowed actions (summon or battle), subject to the constraints. You start with no warrior under your command and are 
not in a rest state initially. Your task is to determine the maximum net gain possible by completing as many summon-battle 
cycles as the days allow.

Example 1:
Input: manaFlux = [1, 2, 3, 0, 2]
Output: 2
Explanation: One optimal sequence could be:
Day 0: Summon a warrior. Cost = manaFlux[0] + min(manaFlux[0..0]) = 1 + 1 = 2 mana.
Day 1: Send warrior to battle. Gain = manaFlux[1] = 2 gold. Enter rest state on Day 2.
Day 2: Rest (cannot summon due to rest state; no warrior to send).
Day 3: Summon a warrior. Cost = manaFlux[3] + min(manaFlux[0..3]) = 0 + 0 = 0 mana.
Day 4: Send warrior to battle. Gain = manaFlux[4] = 2 gold.
Total gold = 2 + 2 = 4, total mana = 2 + 0 = 2, net gain = 4 - 2 = 2.

Example 2:
Input: manaFlux = [1]
Output: 0
Explanation: With only one day, you can summon a warrior for 1 + min(1) = 2 mana but cannot send it to battle before 
the days end. Thus, net gain is 0.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& manaFlux) {
    if (manaFlux.empty()) return 0;
    
    int n = manaFlux.size();
    if (n == 1) return 0;

    vector<int> dp_s1(n, 0);  // no warrior summoned
    vector<int> dp_s2(n, 0);  // warrior summoned but not in battle
    vector<int> dp_s3(n, 0);  // warrior in battle
	
    int min_flux = manaFlux[0];
    
    dp_s1[0] = 0;
    dp_s2[0] = 0 - (2 * manaFlux[0]); // gold earned - mana spent
    dp_s3[0] = INT_MIN;
    
    for (int i = 1; i < n; ++i) {
        min_flux = min(min_flux, manaFlux[i]);
        
        // transitions
        dp_s1[i] = max(dp_s1[i-1], dp_s3[i-1]); // stay there or rest
        dp_s2[i] = max(dp_s2[i-1], dp_s1[i-1] - (manaFlux[i] + min_flux)); // stay there or summon
        dp_s3[i] = dp_s2[i-1] + manaFlux[i]; // battle
    }
    
    return max(dp_s1[n-1], dp_s3[n-1]);
}

int main() {
    vector<int> test = {1, 2, 3, 0, 2};
    cout << maxProfit(test) << endl;
    
    return 0;
}
