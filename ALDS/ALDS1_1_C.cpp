//Prime Numbers
#include <iostream>
#include <cmath>

using namespace std;

bool isPrimeNumber(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    for(int i=2; i*i<=n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, x, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(isPrimeNumber(x)) cnt++;
    }
    cout << cnt << endl;
}
