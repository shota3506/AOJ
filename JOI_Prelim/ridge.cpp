//Ridge
#include <iostream>

using namespace std;

static const int drow[4] = {1, 0, -1, 0};
static const int dcol[4] = {0, 1, 0, -1};
static const int NIL = -1;
static const int RIDGE = -2;

struct Area {
    int h, type;
    Area() {}
    Area(int h, int type): h(h), type(type) {}
};


int main() {
    int H, W, h;
    cin >> H >> W;
    Area A[H][W];
    int order[H * W];
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> h;
            A[i][j] = Area(h, i * W + j);
            order[A[i][j].h - 1] = i * W + j;
        }
    }

    for(int k = 0; k < H * W; k++) {
        int i = order[k] / W;
        int j = order[k] % W;
        int cnt = 0;
        int type = NIL;
        for(int l = 0; l < 4; l++) {
            int si = i + drow[l];
            int sj = j + dcol[l];
            if(si >= 0 && sj >= 0 && si < H && sj < W) {
                if(A[i][j].h > A[si][sj].h) {
                    if(A[si][sj].type == RIDGE) {
                        type = RIDGE;
                        break;
                    } else if(type != NIL && type != A[si][sj].type) {
                        type = RIDGE;
                        break;
                    } else {
                        type = A[si][sj].type;
                    }
                }
            }
        }
        if(type != NIL) A[i][j].type = type;
    }

    int cnt = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j].type == RIDGE) cnt++;
        }
    }

    cout << cnt << endl;
}