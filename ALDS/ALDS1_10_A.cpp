//Fibonacci Number
#include <iostream>

using namespace std;

const int NIL = -1;

int fibonacci(int fib[], int n) {
    if(fib[n] != NIL) return fib[n];
    fib[n] = fibonacci(fib, n - 1) + fibonacci(fib, n - 2);
    return fib[n];
}

int main() {
    int n;
    cin >> n;
    int fib[n + 1];
    for(int i = 0; i < n + 1; i++) {
        fib[i] = NIL;
    }
    fib[0] = 1;
    if(n > 0) fib[1] = 1;

    cout << fibonacci(fib, n) << endl;
}