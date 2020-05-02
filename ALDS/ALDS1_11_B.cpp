//Depth First Search
#include <iostream>
#include <vector>

using namespace std;

static const int N = 100;
static const int WHITE = 0;
static const int BLACK = 1;

int color[N] = {WHITE}, d[N] = {}, f[N] = {}, tt = 1;

void dfs(vector<vector<int>> &G, int u) {
    if(color[u] == BLACK) return;
    color[u] = BLACK;
    d[u] = tt++;
    for(auto v: G[u]) dfs(G, v);
    f[u] = tt++;
}

int main() {
    int n;
    cin >> n;
    int u, k, v;
    vector<vector<int>> G(n);
    for(int i=0; i<n; i++) {
        cin >> u >> k;
        for(int j=0; j<k; j++) {
            cin >> v;
            G[u-1].push_back(v-1);
        }
    }

    for(int i = 0; i < n; i++)
        dfs(G, i);

    for(int i = 0; i < n; i++) cout << i+1 << " " << d[i] << " " << f[i] << endl;
    return 0;
}
