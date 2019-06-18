//Schedule
#include <iostream>

using namespace std;
static const int MOD = 10007;

enum MEMBER {
    J = 0,
    O = 1,
    I = 2
};

int main() {
    int N;
    cin >> N;
    int S[N][8];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 8; j++) {
            S[i][j] = 0;
        }
    }

    char c;
    for(int i = 0; i < N; i++) {
        cin >> c;
        if(i == 0) {
            if(c == 'J') {
                S[i][1] = 1;
                S[i][3] = 1;
                S[i][5] = 1;
                S[i][7] = 1;
            } else if(c == 'O') {
                S[i][3] = 1;
                S[i][7] = 1;
            } else if(c == 'I') {
                S[i][5] = 1;
                S[i][7] = 1;
            }
        } else {
            if(c == 'J') {
                S[i][1] = (S[i - 1][1] + S[i - 1][3] + S[i - 1][5] + S[i - 1][7]) % MOD;
                S[i][3] = (S[i - 1][1] + S[i - 1][2] + S[i - 1][3] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][5] = (S[i - 1][1] + S[i - 1][3] + S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][7] = (S[i - 1][1] + S[i - 1][2] + S[i - 1][3] + S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
            } else if(c == 'O') {
                S[i][2] = (S[i - 1][2] + S[i - 1][3] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][3] = (S[i - 1][1] + S[i - 1][2] + S[i - 1][3] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][6] = (S[i - 1][2] + S[i - 1][3] + S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][7] = (S[i - 1][1] + S[i - 1][2] + S[i - 1][3] + S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
            } else if(c == 'I') {
                S[i][4] = (S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][5] = (S[i - 1][1] + S[i - 1][3] + S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][6] = (S[i - 1][2] + S[i - 1][3] + S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
                S[i][7] = (S[i - 1][1] + S[i - 1][2] + S[i - 1][3] + S[i - 1][4] + S[i - 1][5] + S[i - 1][6] + S[i - 1][7]) % MOD;
            }
        }
    }

    int combination = 0;
    for(int j = 1; j < 8; j++) {
        combination += S[N - 1][j];
    }

    cout << (combination % MOD) << endl;
}