#include <iostream>
#include <vector>
#include <array>

using namespace std;

long long sqr(long long x) {
    return x * x;
}

void solve(long long x, long long y) {
    long long layer = max(x, y);

    if (layer & 1) {
        if (layer == y) cout << sqr(layer) - x + 1;
        else cout << sqr(layer - 1) + y;
    }
    else {
        if (layer == y) cout << sqr(layer - 1) + x;
        else cout << sqr(layer) - y + 1;
    }
    
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    vector<array<long long, 2>> input(t);
    long long x, y;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        input[i] = {x, y};
    }

    for (const auto& [x, y] : input) {
        solve(x, y);
    }
    
    return 0;
}