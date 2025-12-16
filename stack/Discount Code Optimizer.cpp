/*
You have a very long numeric discount code represented as a string.
The marketing department says the code is too long. You must remove exactly k digits from the code.
However, to keep the discount enticing, the resulting number (preserved in relative order) must be the smallest
possible numerical value.

Example:
Input: code = 919293, k = 3
Output: 123
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solve(string num, int k) {
    deque<int> dq;

    for (int i = 0; i < num.size(); i++) {
        while (!dq.empty() && k != 0 && num[i] - '0' < dq.back()) {
            dq.pop_back();
            k--;
        }
        dq.push_back(num[i] - '0');
    }

    while (k) {
        dq.pop_back();
        k--;
    }

    string result;
    for (int i = 0; i < dq.size(); i++) {
        result.push_back(dq[i] + '0');
    }

    // Cut zeros
    int pos = 0;
    while (pos < result.size() && result[pos] == '0')
        pos++;

    result = result.substr(pos);

    if (result.empty()) return "0";
    return result;
}

int main() {
    cout << solve("919293", 3);
    
    return 0;
}