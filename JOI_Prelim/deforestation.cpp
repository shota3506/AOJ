//Deforestation
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

static const int MAX = 30;
static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};

struct State {
    int x, y, step, cost;
    State(int x, int y, int step, int cost): x(x), y(y), step(step), cost(cost) {}
    bool operator < (const State &arg) const {
        return cost > arg.cost;
    }
};

int A[MAX][MAX], d[MAX][MAX][MAX * MAX + 1];
int H, W;

bool isInRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < W && y < H);
}

int solve() {
    priority_queue<State> PQ;
    PQ.push(State(0, 0, 0, 0));
    int ans = INT_MAX;
    while(!PQ.empty()) {
        State s = PQ.top();
        PQ.pop();
        if(s.x == W - 1 && s.y == H - 1) {
            ans = min(ans, s.cost - s.step);
            continue;
        }
        if(s.step > H * W) continue;
        if(s.cost > d[s.x][s.y][s.step]) continue;
        for(int r = 0; r < 4; r++) {
            int x = s.x + dx[r];
            int y = s.y + dy[r];
            if(!isInRange(x, y )) continue;
            int step = s.step + 1;
            int cost = s.cost + 1 + A[y][x] * (2 * s.step + 1);
            if(d[x][y][step] > cost) {
                d[x][y][step] = cost;
                PQ.push(State(x, y, step, cost));
            }
        }
    }
    return ans;
}

int main() {
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            for(int k = 0; k <= MAX * MAX; k++) {
                d[i][j][k] = INT_MAX;
            }
        }
    }

    cout << solve() << endl;
}