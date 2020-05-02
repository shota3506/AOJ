//Fibonacci Number
#include <iostream>

using namespace std;

int fibonacci(int n) {
    if(n == 0 || n == 1) return 1;

    int dp[n+1];
    dp[0] = 1; dp[1] = 1;
    for(int i=2; i<n+1; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}
