//Plush Toys
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int A[N + 1], cumsum[M][N + 1];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N + 1; j++) {
            cumsum[i][j] = 0;
        }
    }

    for (int i = 1; i < N + 1; i++) {
        cin >> A[i];
        A[i]--;
        cumsum[A[i]][i]++;
    }

    for(int i = 0; i < M; i++) {
        for(int j = 1; j < N + 1; j++) {
            cumsum[i][j] += cumsum[i][j - 1];
        }
    }

    int dp[1 << M];
    for(int i = 0; i < (1 << M); i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int s = 0; s < (1 << M); s++) {
        int p = 0;
        for(int i = 0; i < M; i++) {
            if(s & 1 << i) p += cumsum[i][N];
        }
        for(int i = 0; i < M; i++) {
            if(s & 1 << i) continue;
            int cost = dp[s] + (cumsum[i][N] - cumsum[i][p + cumsum[i][N]] + cumsum[i][p]);
            dp[s + (1 << i)] = min(dp[s + (1 << i)], cost);
        }
    }

    cout << dp[(1 << M) - 1] << endl;
}