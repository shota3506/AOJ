#include <iostream>
#include <climits>

using namespace std;

static const int MAX = 25;
int H, W;
int A[MAX][MAX];

int distance(int k, int l) {
    int d = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            d += A[i][j] * min(abs(i - k), abs(j -l));
        }
    }
    return d;
}

int main() {
    int mind = INT_MAX;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            mind = min(mind, distance(i, j));
        }
    }
    cout << mind << endl;
}