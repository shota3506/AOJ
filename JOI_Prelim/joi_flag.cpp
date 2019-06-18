//JOI Flag
#include <iostream>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    char F[M][N];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> F[i][j];
        }
    }

//    現在の場所, その直前 N 個の文字において隣り合う 2 列の文字がそれぞれ "JO" となっているか否か, 直前 1 個の文字が J であるか否か
    int dp[M][N][2][2];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j][0][0] = 0;
            dp[i][j][0][1] = 0;
            dp[i][j][1][0] = 0;
            dp[i][j][1][1] = 0;
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(i == 0) {
                switch(F[i][j]) {
                    case '?':
                        break;
                    case 'J':
                        dp[i][j][]
                    case 'O':
                    case 'I':
                    default:
                        break;
                }
            } else {

            }
        }
    }
}