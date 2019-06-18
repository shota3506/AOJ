//8 Puzzle
#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

static const int N = 3;
static const int N2 = 9;
static const char dir[4] = {'u', 'l', 'd', 'r'};
static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};

struct Puzzle {
    int f[N2];
    int space;
    string path;

    bool operator < (const Puzzle &p) const {
        for(int i = 0; i < N2; i++) {
            if(f[i] == p.f[i]) continue;
            return f[i] > p.f[i];
        }
        return false;
    }
};

bool isTarget(Puzzle p) {
    for(int i = 0; i < N2; i++) {
        if(p.f[i] != (i + 1)) return false;
    }
    return true;
}

string bfs(Puzzle p) {
    queue<Puzzle> Q;
    map<Puzzle, bool> V;
    Puzzle u, v;
    p.path = "";
    Q.push(p);
    V[p] = true;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        if(isTarget(u)) return u.path;
        int sx = u.space % N;
        int sy = u.space / N;
        for(int r = 0; r < 4; r++) {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if(tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
            v = u;
            v.space = tx + N * ty;
            swap(v.f[v.space], v.f[u.space]);
            if(!V[v]) {
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}

int main() {
    Puzzle in;
    for(int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if(in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }

    cout << bfs(in).size() << endl;
}