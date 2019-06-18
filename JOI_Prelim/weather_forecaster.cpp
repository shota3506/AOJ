//Weather Forecaster
#include <iostream>

using namespace std;

static const int NIL = -1;

enum WEATHER {
    SUNNY,
    CLOUDY
};

int main() {
    int H, W;
    cin >> H >> W;
    int A[H][W], T[H][W];
    char c;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> c;
            if(c == '.') {
                A[i][j] = SUNNY;
                T[i][j] = NIL;
            }
            else if(c == 'c') {
                A[i][j] = CLOUDY;
                T[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 1; j < W; j++) {
            if(A[i][j] == CLOUDY) continue;
            if(T[i][j - 1] == NIL) continue;
            T[i][j] = T[i][j - 1] + 1;
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(j != 0) cout << " ";
            cout << T[i][j];
        }
        cout << endl;
    }

    return 0;
}