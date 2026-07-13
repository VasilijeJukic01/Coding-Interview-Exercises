#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int longest = 1;
    string s;
    
    cin >> s;
    int curr = 1;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            curr++;
            longest = max(longest, curr);
        }
        else curr = 1;
    }
    
    cout << longest;

    return 0;
}