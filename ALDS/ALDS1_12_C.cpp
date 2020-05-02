//Single Source Shortest Path II
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

static const int N = 10000;
static const int WHITE = 0;
static const int BLACK = 1;
int d[N];

void dijkstra(vector<vector<pair<int, int>>> G, int n) {
    int colors[n];
    for(int i = 0; i < n; i++) {
        colors[i] = WHITE;
        d[i] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    d[0] = 0;
    pq.push(make_pair(0, 0));
    while(!pq.empty()) {
        pair<int, int> f = pq.top();
        pq.pop();

        int u = f.second;
        if(d[u] < f.first) continue;
        if(colors[u] == BLACK) continue;
        for(int i = 0; i < G[u].size(); i++) {
            if(d[G[u][i].first] > f.first + G[u][i].second) {
                d[G[u][i].first] = f.first + G[u][i].second;
                pq.push(make_pair(d[G[u][i].first], G[u][i].first));
            }

        }
    }
}

int main() {
    int n, u, k, v, c;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);

    for(int i = 0; i < n; i++) {
        cin >> u >> k;
        for(int j = 0; j < k; j++) {
            cin >> v >> c;
            G[u].push_back(make_pair(v, c));
        }
    }

    dijkstra(G, n);

    for(int i = 0; i < n; i++) cout << i << " " << d[i] << endl;

    return 0;
}
