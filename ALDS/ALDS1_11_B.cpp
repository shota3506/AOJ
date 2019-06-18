//Depth First Search
#include <iostream>

using namespace std;

static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[N][N];
int colors[N] = {}, d[N] = {}, f[N] = {}, tt = 1;

void dfs_visit(int u) {
    if(colors[u] == GRAY || colors[u] == BLACK) return;
    d[u] = tt++;
    colors[u] = GRAY;
    for(int i = 0; i < n; i++) {
        if(M[u][i] == 1) dfs_visit(i);
    }
    f[u] = tt++;
    colors[u] = BLACK;
}

void dfs() {
    for(int i = 0; i < n; i++) {
        dfs_visit(i);
    }
    for(int i = 0; i < n; i++) {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    int u, k, v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) M[i][j] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> u >> k;
        for(int j = 0; j < k; j++) {
            cin >> v;
            M[u - 1][v - 1] = 1;
        }
    }

    dfs();
}