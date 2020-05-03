//Greatest Common Divisor
#include <iostream>
#include <cmath>

using namespace std;

int greatestCommonDivisor(int a, int b) {
    if(a < b) swap(a, b);
    while(a%b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return b;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << greatestCommonDivisor(a, b) << endl;
}