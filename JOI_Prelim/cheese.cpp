//Cheese
#include <iostream>
#include <queue>

using namespace std;
static const int MAX = 1000;
static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, 1, 0, -1};

int H, W, N, gx, gy;
int A[MAX][MAX];
bool visited[MAX][MAX];

struct State {
    int x, y, d;
    State() {}
    State(int x, int y, int d): x(x), y(y), d(d) {}
};

int bfs(int t, int x, int y) {
    queue<State> Q;
    Q.push(State(x, y, 0));
    for(int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            visited[i][j] = false;
        }
    }
    visited[y][x] = true;
    while(!Q.empty()) {
        State s = Q.front();
        Q.pop();
        if(A[s.y][s.x] == t) {gx = s.x; gy = s.y; return s.d;}
        for(int i = 0; i < 4; i++) {
            int sx, sy;
            sx = s.x + dx[i];
            sy = s.y + dy[i];
            if(sx >= 0 && sy >= 0 && sx < W && sy < H) {
                if(A[sy][sx] == -1) continue;
                if(visited[sy][sx]) continue;
                Q.push(State(sx, sy, s.d + 1));
                visited[sy][sx] = true;
            }
        }
    }
    return 0;
}

int main() {
    cin >> H >> W >> N;
    char c;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> c;
            if(c == '.') A[i][j] = 0;
            else if(c == 'X') A[i][j] = -1;
            else if(c == 'S') {A[i][j] = 0; gx = j; gy = i;}
            else A[i][j] = c - '0';
        }
    }

    int d = 0;
    for(int i = 1; i < N + 1; i++) d += bfs(i, gx, gy);

    cout << d << endl;

    return 0;
}