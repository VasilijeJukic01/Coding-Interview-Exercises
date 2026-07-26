#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll increments = 0;
    ll prev = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < prev) {
            increments += prev - arr[i];
        }
        else prev = arr[i];
    }
    
    cout << increments;
    
    return 0;
}