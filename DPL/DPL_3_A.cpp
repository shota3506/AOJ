//Largest Square
#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX = 1400;

int dp[MAX][MAX], G[MAX][MAX];
int H, W;

int getLargestSquare() {
    int maxWidth = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            dp[i][j] = (G[i][j] + 1) % 2;
            maxWidth |= dp[i][j];
        }
    }

    for(int i = 1; i < H; i++) {
        for(int j = 1; j < W; j++) {
            if(dp[i][j] == 0) continue;
            dp[i][j] += min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            maxWidth = max(maxWidth, dp[i][j]);
        }
    }
    return maxWidth * maxWidth;
}

int main() {
    int c;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) cin >> G[i][j];
    }

    cout << getLargestSquare() << endl;
}
