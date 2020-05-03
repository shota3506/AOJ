//0-1 Knapsack Problem
#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
public:
    int v, w;
    Item(int v=0, int w=0): v(v), w(w) {}
};

int main() {
    int N , W, v, w;
    cin >> N >> W;
    Item items[N+1];
    for(int i=1; i<N+1; i++) {
        cin >> v >> w;
        items[i] = Item(v, w);
    }

    int dp[N+1][W+1];
    for(int j=0; j<W+1; j++) dp[0][j] = 0;

    for(int i=1; i<N+1; i++) {
        for(int j=0; j<W+1; j++) dp[i][j] = dp[i-1][j];
        for(int j=0; j<W+1; j++) {
            if(items[i].w + j <= W) {
                if(i==0) dp[i][items[i].w + j] = items[i].v;
                else dp[i][items[i].w + j] = max(dp[i][items[i].w + j], dp[i-1][j] + items[i].v);
            }
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}