//0-1 Knapsack Problem
#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
public:
    int v, w;
    explicit Item(int v = 0, int w = 0): v(v), w(w) {}
};

int main() {
    int N , W, v, w;
    cin >> N >> W;
    Item items[N];
    for(int i = 0; i < N; i++) {
        cin >> v >> w;
        items[i] = Item(v, w);
    }

    int C[N][W + 1];
    for(int i=0; i<N; i++) {
        C[i][0] = 0;
        for(int j=1; j<W+1; j++) {
            if(i == 0) C[i][j] = (j < items[i].w) ? 0 : items[i].v;
            else {
                if(j < items[i].w) C[i][j] = C[i-1][j];
                else C[i][j] = max(C[i-1][j], C[i-1][j-items[i].w] + items[i].v);
            }
        }
    }

    cout << C[N - 1][W] << endl;

    return 0;
}