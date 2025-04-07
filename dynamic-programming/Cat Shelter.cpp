/*
In a cozy cat shelter, the caretaker has a collection of adorable cats, each with a specific amount of 
fluffiness measured in "fluff units." The caretaker wants to divide these cats into two groups for a special 
playtime event, but she has a unique requirement: the total fluffiness of the cats in each group must be exactly 
the same. She represents the fluffiness of each cat as an integer in an array called cats, where each element 
cats[i] is the fluffiness of the i-th cat. Your task is to help the caretaker determine if it's possible to split 
the cats into two groups (subsets) such that the sum of fluffiness in both groups is equal. Return true if this is 
possible, and false otherwise.

For example, imagine the caretaker has four cats with the following fluffiness levels: [2, 4, 6, 8]. 
She could split them into two groups like [2, 8] (sum = 10) and [4, 6] (sum = 10). Since both groups 
have equal fluffiness, this would work! However, if the cats had fluffiness levels of [1, 3, 5, 7], no matter 
how she tries to split them, she can't find two groups with equal sums, so it wouldn’t be possible.

The shelter has some rules and limitations:

- There must be at least 1 cat and at most 200 cats in the collection (1 <= cats.length <= 200).
- Each cat's fluffiness is a positive integer between 1 and 100 (1 <= cats[i] <= 100).
- The two groups don’t need to have the same number of cats, but every cat must be assigned to exactly one 
group (no cat can be left out or counted in both groups).

Input: cats = [1, 5, 11, 5]
Output: true
Explanation: The cats can be split into [1, 5, 5] (sum = 11) and [11] (sum = 11). Equal fluffiness achieved!

Input: cats = [1, 2, 3, 5]
Output: false
Explanation: No way to split these cats into two groups with equal fluffiness sums.

Input: cats = [2, 2]
Output: true
Explanation: The cats can be split into [2] and [2], both with a fluffiness sum of 2.
*/

#include <iostream>
#include <vector>

using namespace std;

bool classifyCats(vector<int> cats) {
    if (cats.size() == 0 || cats.size() > 200) 
        return false;
    
    int totalFluffines = 0;
    for (int fluffiness : cats) {
        if (fluffiness < 0 || fluffiness > 100) 
            return false;
        totalFluffines += fluffiness;
    }
    
    if (totalFluffines & 1) return false;
    
    int fluffinessGoal = totalFluffines / 2;
    vector<bool> dp(fluffinessGoal + 1, false);
    dp[0] = true;
    
    for (int i = 0; i < cats.size(); i++) {
        for (int j = fluffinessGoal; j >= cats[i]; j--) {
            dp[j] = dp[j] || dp[j - cats[i]];
            if (dp[fluffinessGoal]) return true;
        }
    }
    
    return dp[fluffinessGoal];
}

int main() {
    vector<int> cats = {2, 4, 6, 8};
    
    if (classifyCats(cats))
        cout << "We can classify cats in two groups";
    else
        cout << "We cant classify cats in two groups";

    return 0;
}