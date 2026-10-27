#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    auto sqr = [](ll x) { 
        return x * x; 
    };
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        ll total = sqr(i) * (sqr(i) - 1) / 2;
        ll invalid = max(0LL, 4LL * (i - 1) * (i - 2));
        
        cout << total - invalid << endl;
    }
    
    return 0;
}