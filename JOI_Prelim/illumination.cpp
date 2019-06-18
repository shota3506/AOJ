//Illumination
#include <iostream>
#include <queue>

using namespace std;
static const int MAX = 100;
static const int dx1[6] = {1, 1, 0, -1, 0, 1};
static const int dy1[6] = {0, 1, 1, 0, -1, -1};
static const int dx2[6] = {1, 0, -1, -1, -1, 0};
static const int dy2[6] = {0, 1, 1, 0, -1, -1};

int W, H;
bool A[MAX][MAX], B[MAX][MAX], visited[MAX][MAX];

void bfs(int x, int y) {
    if(A[y][x]) return;
    if(visited[y][x]) return;
    queue<pair<int, int> > Q;
    Q.push(make_pair(x, y));
    visited[y][x] = true;
    while(!Q.empty()) {
        pair<int, int> p = Q.front();
        Q.pop();
        B[p.second][p.first] = false;
        for(int i = 0; i < 6; i++) {
            int sx, sy;
            if(p.second % 2 == 0) {
                sx = p.first + dx1[i];
                sy = p.second + dy1[i];
            } else {
                sx = p.first + dx2[i];
                sy = p.second + dy2[i];
            }
            if(sx < 0 || sy < 0 || sx >= W || sy >= H) continue;
            if(A[sy][sx]) continue;
            if(visited[sy][sx]) continue;
            Q.push(make_pair(sx, sy));
            visited[sy][sx] = true;
        }
    }
}

int main() {
    cin >> W >> H;
    for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
            cin >> A[i][j];
    for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
            B[i][j] = true;
    for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
            visited[i][j] = false;

    for(int i = 0; i < H; i++) {
        bfs(0, i);
        bfs(W - 1, i);
    }
    for(int j = 0; j < W; j++) {
        bfs(j, 0);
        bfs(j, H - 1);
    }

    int cnt = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(!B[i][j]) continue;
            for(int k = 0; k < 6; k++) {
                int sx, sy;
                if(i % 2 == 0) {
                    sx = j + dx1[k];
                    sy = i + dy1[k];
                } else {
                    sx = j + dx2[k];
                    sy = i + dy2[k];
                }
                if(sx < 0 || sy < 0 || sx >= W || sy >= H) {cnt++; continue;}
                if(!B[sy][sx]) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}