//Largest Square
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int largestSquare(int h, int w, vector<vector<int>> &G) {
    vector<vector<int>> dp(h+1, vector<int>(w+1, 0));

    int s = 0;
    for(int i=1; i<h+1; i++) {
        for(int j=1; j<w+1; j++) {
            if(G[i][j] == 1) continue;
            dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            s = max(s, dp[i][j]);
        }
    }

    return s*s;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> G(h+1, vector<int>(w+1, 1));
    for(int i=1; i<h+1; i++)
        for(int j=1; j<w+1; j++)
            cin >> G[i][j];

    cout << largestSquare(h, w, G) << endl;

    return 0;
}