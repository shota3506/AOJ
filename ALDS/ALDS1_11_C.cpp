//Breadth First Search
#include <iostream>
#include <queue>

using namespace std;

static const int N = 100;

int n, M[N][N];
int d[N];
queue<int> Q;

void bfs() {
    int u;
    for(int i = 0; i < N; i++) d[i] = -1;
    Q.push(0);
    d[0] = 0;
    while(!Q.empty()) {
        u = Q.front();
        for(int i = 0; i < n; i++) {
            if(M[u][i] == 1 && d[i] == -1) {
                Q.push(i);
                d[i] = d[u] + 1;
            }
        }
        Q.pop();
    }
    for(int i = 0; i < n; i++) {
        cout << i + 1 << " " << d[i] << endl;
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

    bfs();
}