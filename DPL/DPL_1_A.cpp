//Coin Chaining Problem
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int C[m];
    for(int i=0; i<m; i++) cin >> C[i];

    int dp[n+1];
    for(int i=0; i<n+1; i++) {
        dp[i] = i;
        for(int j=0; j<m; j++) {
            if(i-C[j]>=0) dp[i] = min(dp[i], dp[i-C[j]]+1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
