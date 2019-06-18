//Pasta
#include <iostream>
#include <map>

using namespace std;

static const int MOD = 10000;

int main() {
    int N, K, a, b;
    cin >> N >> K;
    map<int, int> m;
    for(int i = 0; i < K; i++) {
        cin >> a >> b;
        m.insert(make_pair(a - 1, b - 1));
    }
    int dp[N][3][3];
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    auto itr1 = m.find(0);
    if(itr1 == m.end()) {
        for(int j = 0; j < 3; j++) {
            auto itr2 = m.find(1);
            if(itr2 == m.end()) {
                for (int k = 0; k < 3; k++) {
                    dp[1][j][k] = 1;
                }
            } else dp[1][j][itr2 -> second] = 1;
        }
    } else {
        auto itr2 = m.find(1);
        if(itr2 == m.end()) {
            for (int k = 0; k < 3; k++) {
                dp[1][itr1 -> second][k] = 1;
            }
        } else dp[1][itr1 -> second][itr2 -> second] = 1;
    }

    for(int i = 2; i < N; i++) {
        auto itr = m.find(i);
        if(itr == m.end()) {
            for(int k = 0; k < 3; k++) {
                for(int j = 0; j < 3; j++) {
                    if(j != k) dp[i][j][k] = dp[i - 1][0][j] + dp[i - 1][1][j] + dp[i - 1][2][j];
                    else dp[i][j][k] = dp[i - 1][0][j] + dp[i - 1][1][j] + dp[i - 1][2][j] - dp[i - 1][j][j];
                    dp[i][j][k] %= MOD;
                }
            }
        } else {
            for(int j = 0; j < 3; j++) {
                if(j != itr -> second) dp[i][j][itr -> second] = dp[i - 1][0][j] + dp[i - 1][1][j] + dp[i - 1][2][j];
                else dp[i][j][itr -> second] = dp[i - 1][0][j] + dp[i - 1][1][j] + dp[i - 1][2][j] - dp[i - 1][j][j];
                dp[i][j][itr -> second] %= MOD;
            }
        }
    }

    int c = 0;
    for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++)
            c += dp[N - 1][j][k];
    c %= MOD;

    cout << c << endl;

    return 0;
}