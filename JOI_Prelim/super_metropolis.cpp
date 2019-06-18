//Super Metropolis
#include <iostream>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    int x, y, sx, sy, cost = 0;
    for(int i = 0; i < N; i++) {
        cin >> sx >> sy;
        if(i != 0) {
            if((x - sx) * (y - sy) >= 0) cost += max(abs(x - sx), abs(y - sy));
            else cost += abs(x - sx) + abs(y - sy);
        }
        x = sx;
        y = sy;
    }

    cout << cost << endl;
}