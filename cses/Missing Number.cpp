#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    
    ll sum = n*(n + 1) / 2;
    ll count = 0;
    
    int x;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        count += x;
    }
    
    cout << (sum - count);

    return 0;
}