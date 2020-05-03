//Longest Increasing Subsequence
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    int dp[n+1];
    int length = 0;
    dp[length] = A[0];

    for(int i=1; i<n; i++) {
        if(A[i] > dp[length]) dp[++length] = A[i];
        else *lower_bound(dp, dp+length, A[i]) = A[i];
    }

    cout << length+1 << endl;

    return 0;
}