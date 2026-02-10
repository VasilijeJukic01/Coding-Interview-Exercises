#include <iostream>

using namespace std;

void printBits(unsigned x) {
    unsigned len = sizeof(unsigned) * 8;
    for (unsigned mask = 1 << (len - 1); mask; mask >>=1) {
        cout << ((x & mask) ? "1" : "0");
    }
}

unsigned solve(unsigned x, unsigned k, unsigned p) {
    return x & (~(~(~0 << k) << (p - k)));
}

int main() {
    
    unsigned x = 31;
    printBits(x);
    cout << endl;
    printBits(solve(x, 2, 3));

    return 0;
}