//Largest Square
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

static const int MAX = 1400;

struct Rectangle {
public:
    int height, pos;
    Rectangle(int height, int pos): height(height), pos(pos) {}
};

int G[MAX][MAX];
int H, W;

int getLargestRectangle() {
    stack<Rectangle> S;
    int dp[H][W];
    int maxArea = 0;

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            dp[i][j] = (G[i][j] + 1) % 2;
            if(i != 0 && dp[i][j] != 0) dp[i][j] += dp[i-1][j];
        }
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            Rectangle rect = Rectangle(dp[i][j], j);
            if(S.empty()) S.push(rect);
            else if(S.top().height < rect.height) S.push(rect);
            else {
                int pos = j;
                while(!S.empty() && S.top().height > rect.height) {
                    maxArea = max(maxArea, (j - S.top().pos) * S.top().height);
                    pos = S.top().pos;
                    S.pop();
                }
                rect.pos = pos;
                S.push(rect);
            }
        }
        while(!S.empty()) {
            maxArea = max(maxArea, (W - S.top().pos) * S.top().height);
            S.pop();
        }
    }
    
    return maxArea;

}

int main() {
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) cin >> G[i][j];
    }

    cout << getLargestRectangle() << endl;

    return 0;
}
