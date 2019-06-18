//Connected Component
#include <iostream>
#include <vector>

using namespace std;

static const int N = 100000;
int n, colors[N] = {};
vector<int> G[N];

void dfs_visit(int u, int c) {
    if(colors[u] == c) return;
    colors[u] = c;
    for(int i = 0; i < G[u].size(); i++) {
        dfs_visit(G[u][i], c);
    }
}

void dfs() {
    for(int i = 0; i < N; i++) colors[i] = -1;
    for(int i = 0; i < n; i++) {
        if(colors[i] == -1) {
            dfs_visit(i, i);
        }
    }
}

int main() {
    int m, s, t, q;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    dfs();

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> s >> t;
        if(colors[s] == colors[t]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
