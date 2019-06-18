//Single Source Shortest Path II
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

static const int N = 10000;
static const int WHITE = 0;
static const int BLACK = 1;
int n, colors[N], d[N];
vector<pair<int, int> > G[N];


void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    for(int i = 0; i < N; i++) {
        colors[i] = WHITE;
        d[i] = INT_MAX;
    }
    d[0] = 0;
    PQ.push(make_pair(0, 0));
    while(!PQ.empty()) {
        pair<int, int> f = PQ.top();
        PQ.pop();
        int u = f.second;
        if(colors[u] == BLACK) continue;
        for(int i = 0; i < G[u].size(); i++) {
            if(d[G[u][i].first] > f.first + G[u][i].second) {
                d[G[u][i].first] = f.first + G[u][i].second;
                PQ.push(make_pair(d[G[u][i].first], G[u][i].first));
            }

        }
    }
}

int main() {
    int u, k, v, c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u >> k;
        for(int j = 0; j < k; j++) {
            cin >> v >> c;
            G[u].push_back(make_pair(v, c));
        }
    }

    dijkstra();

    for(int i = 0; i < n; i++) {
        cout << i << " " << d[i] << endl;
    }
}