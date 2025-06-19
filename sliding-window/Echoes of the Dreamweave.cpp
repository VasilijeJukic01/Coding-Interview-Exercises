/**
In the ethereal realm of Somnara, dreams are woven into intricate tapestries of symbols, each a 
fragment of a dreamer’s subconscious—letters, numbers, or mystical glyphs like stars or spirals. 
These dream sequences are stored in the Celestial Loom, a vast archive pulsing with the rhythm of 
countless imaginations. The Dreamweavers, guardians of this realm, seek to uncover the purest 
thread in a dream sequence, known as the Unraveled Vision. This thread is the longest stretch of 
the dream where no symbol appears more than once, representing a moment of vivid, unrepeated 
imagination.

Your task is to assist the Dreamweavers by analyzing a dream sequence, represented as s, and 
determining the length of the Unraveled Vision, the longest portion of the sequence where each 
symbol is unique within that stretch. For instance, in the dream sequence "slumber", the Unraveled 
Vision might be "lumb", spanning 4 symbols, as no symbol repeats within it. In contrast, a 
monotonous sequence like "zzz" yields an Unraveled Vision of just "z", with a length of 1, as the 
dream stalls in repetition. The Dreamweavers insist that the Vision must be an unbroken thread, not 
a collection of symbols plucked from different parts of the sequence (in their words, “no skipping, 
lest the dream dereferences its own meaning”).

The Dreamweavers’ work is delicate, akin to debugging the fabric of imagination itself. They speak 
of “hash collisions” when symbols repeat, mutter about “optimizing the runtime” of their analysis, 
and warn of the need to “map” the dream’s flow. Your solution must navigate these constraints to 
return the length of the longest Unraveled Vision, ensuring the dream’s essence remains intact.

Example 1
Input: s = "visionary"
Output: 7
Explanation: The Unraveled Vision is "sionary", with a length of 7. No longer thread exists without a 
symbol appearing more than once.

Example 2
Input: s = "aaaaa"
Output: 1
Explanation: The Unraveled Vision is "a", with a length of 1. The dream is stuck in a repetitive 
stack overflow of identical symbols.

Example 3
Input: s = "star gaze"
Output: 6
Explanation: The Unraveled Vision is "star g", with a length of 6 (including the space, a valid 
glyph in Somnara). The space acts as a delimiter in the dream’s syntax, but no symbol repeats in 
this thread.

Constraints:
0 <= s.length <= 10^5
s consists of Somnaran glyphs: English letters, digits, mystical symbols (e.g., *, !, ?), and spaces.
The dream sequence s is always a valid string, parsed correctly by the Celestial Loom’s ancient 
compiler.
If s is empty, return 0, as no Unraveled Vision can be woven from nothingness.
*/

#include <iostream>
#include <vector>

using namespace std;

int solve(string s) {
    vector<int> map(256, 0);
    int maxLen = 0;
    int left = 0;
    
    for (int right = 0; right < s.size(); right++) {
        map[s[right]]++;
        while (map[s[right]] > 1) {
            map[s[left]]--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

int main() {
    string s = "star gaze";
    cout << solve(s);
    
    return 0;
}
