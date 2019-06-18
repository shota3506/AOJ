//A First Grader
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    ll dp[N - 1][21];
    for(int i = 0; i < N - 1; i++) for(int j = 0; j < 21; j++)
            dp[i][j] = 0;
    dp[0][A[0]]++;
    for(int i = 1; i < N - 1; i++) {
        for(int j = 0; j < 21; j++) {
            if(dp[i - 1][j] == 0) continue;
            int ans = j + A[i];
            if(ans <= 20) dp[i][ans] += dp[i - 1][j];
            ans = j - A[i];
            if(ans >= 0) dp[i][ans] += dp[i - 1][j];
        }
    }

    cout << dp[N - 2][A[N - 1]] << endl;

    return 0;
}