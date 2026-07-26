#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    if (n == 1) cout << "1";
    else if (n == 2 || n == 3) cout << "NO SOLUTION";
    else {
        vector<int> result(n + 1, 0);
        
        int mid = n / 2 + (n & 1);
        
        int ptr = 1;
        int num = mid;
        for (int i = 0; i < mid; i++) {
            result[ptr] = num;
            num--;
            ptr += 2;
        }
        
        ptr = 2;
        num = n;
        int c = n & 1;
        for (int i = 0; i < mid - c; i++) {
            result[ptr] = num;
            num--;
            ptr += 2;
        }
        
        for (int i = 1; i <= n; i++) {
            cout << result[i] << " ";
        }
    }
    
    return 0;
}