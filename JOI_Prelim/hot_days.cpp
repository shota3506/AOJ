//Hot Days
#include <iostream>

using namespace std;

static const int NIL = -1;

struct Clothes {
    int a, b, c;
    Clothes() {}
    Clothes(int a, int b, int c): a(a), b(b), c(c) {}
};

int main() {
    int D, N, a, b, c;
    cin >> D >> N;
    int T[D];
    Clothes C[N];
    for(int i = 0; i < D; i++) cin >> T[i];
    for(int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        C[i] = Clothes(a, b, c);
    }

    int dp[D][101];

    for(int i = 0; i < D; i++) for(int j = 0; j < 101; j++) dp[i][j] = NIL;
    for(int i = 0; i < D; i++) {
        for(int j = 0; j < N; j++) {
            if(C[j].a <= T[i] && C[j].b >= T[i]) {
                if(i == 0) dp[0][C[j].c] = 0;
                else {
                    for(int k = 0; k < 101; k++) {
                        if(dp[i - 1][k] == NIL) continue;
                        dp[i][C[j].c] = max(dp[i][C[j].c], dp[i - 1][k] + abs(k - C[j].c));
                    }
                }
            }
        }
    }

    int maxv = 0;
    for(int i = 0; i < 101; i++) {
        maxv = max(maxv, dp[D - 1][i]);
    }
    cout << maxv << endl;
}