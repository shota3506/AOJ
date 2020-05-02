//Breadth First Search
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static const int N = 100;

int d[N];

void bfs(vector<vector<int>> &G, int s) {
    queue<int> q;
    q.push(s);
    d[s] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: G[u]) {
            if(d[v] != -1) continue;
            q.push(v);
            d[v] = d[u] + 1;
        }
    }
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
    for(int i=0; i<n; i++) d[i] = -1;

    bfs(G, 0);

    for(int i = 0; i < n; i++) cout << i+1 << " " << d[i] << endl;
    return 0;
}
