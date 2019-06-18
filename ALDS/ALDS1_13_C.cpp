//15 Puzzle
#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

static const int N = 4;
static const int N2 = 16;
static const int LIMIT = 100;
static const char dir[4] = {'u', 'l', 'd', 'r'};
static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};

int MDT[N2][N2];
int path[LIMIT];

struct Puzzle {
    int f[N2];
    int space;
    int MD;
};

int getAllMD(Puzzle p) {
    int sum = 0;
    for(int i = 0; i < N2; i++) {
        if(p.f[i] == N2) continue;
        sum += MDT[i][p.f[i] - 1];
    }
    return sum;
}

bool dfs(Puzzle p, int limit, int depth, int prev) {
    if(p.MD == 0) return true;
    if(depth + p.MD > limit) return false;

    int sx = p.space % N;
    int sy = p.space / N;
    Puzzle q;

    for(int r = 0; r < 4; r++) {
        if(max(prev, r) - min(prev, r) == 2) continue;
        int tx = sx + dx[r];
        int ty = sy + dy[r];
        if(tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
        q = p;
        q.space = tx + N * ty;
        swap(q.f[q.space], q.f[p.space]);
        q.MD -= MDT[q.space][p.f[q.space] - 1];
        q.MD += MDT[p.space][p.f[q.space] - 1];
        if(dfs(q, limit, depth + 1, r)) {
            path[depth] = r;
            return true;
        }
    }
    return false;
}

string iterative_deepening(Puzzle in) {
    in.MD = getAllMD(in);
    for(int limit = in.MD; limit <= LIMIT; limit++) {
        if(dfs(in, limit, 0, -100)) {
            string ans = "";
            for(int i = 0; i < limit; i++) ans += dir[path[i]];
            return ans;
        }
    }
    return "unsolvable";
}

int main() {
    for(int i = 0; i < N2; i++) {
        for(int j = 0; j < N2; j++) {
            MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    Puzzle in;
    for(int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if(in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }

    cout << iterative_deepening(in).size() << endl;
}