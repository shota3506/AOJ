//Sandcastle
#include <iostream>
#include <queue>
#include <set>

using namespace std;

static const int drow[8] = {0, -1, -1, -1, 0, 1, 1, 1};
static const int dcol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    int S[H + 2][W + 2], T[H + 1][W + 1];
    for(int i = 0; i < H + 2; i++) {
        S[i][0] = 0;
        S[i][W + 1] = 0;
    }
    for(int j = 0; j < W + 2; j++) {
        S[0][j] = 0;
        S[H + 1][j] = 0;
    }
    char c;
    for(int i = 1; i < H + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            cin >> c;
            if(c == '.') S[i][j] = 0;
            else S[i][j] = c - '0';
        }
    }

    queue<int> P, Q;
    set<int> E;
    for(int i = 1; i < H + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            T[i][j] = 0;
            for(int k = 0; k < 8; k++) {
                int si = i + drow[k];
                int sj = j + dcol[k];
                if(S[si][sj] == 0) T[i][j]++;
            }
            if(S[i][j] != 0 && T[i][j] >= S[i][j]) {
                P.push(i * W + j);
                E.insert(i * W + j);
            }
        }
    }

    int cnt = 0;
    while(!P.empty() || !Q.empty()) {
        while(!P.empty()) {
            int i = P.front() / W;
            int j = P.front() % W;
            P.pop();
            S[i][j] = 0;
            for(int k = 0; k < 8; k++) {
                int si = i + drow[k];
                int sj = j + dcol[k];
                T[si][sj]++;
                if(S[si][sj] != 0 && T[si][sj] >= S[si][sj] && E.find(si * W + sj) == E.end()) {
                    Q.push(si * W + sj);
                    E.insert(si * W + sj);
                }
            }
        }
        swap(P, Q);
        cnt++;
    }

    cout << cnt << endl;
}