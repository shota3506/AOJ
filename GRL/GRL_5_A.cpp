//Diameter of a Tree
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static const int MAX = 100000;

struct Edge {
public:
    int t, w;
    Edge(int t, int w): t(t), w(w) {}
};

int N;
vector<Edge> G[MAX];
queue<int> Q;
bool visited[MAX];
int d[MAX];

void bfs(int u) {
    int v;
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
        d[i] = 0;
    }
    Q.push(u);
    visited[u] = true;
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (auto e : G[v]) {
            if (!visited[e.t]) {
                Q.push(e.t);
                visited[e.t] = true;
                d[e.t] = d[v] + e.w;
            }
        }
    }
}

int diameter() {
    int x, y, maxd = 0;
    bfs(0);
    for(int i = 0; i < N; i++) {
        if(maxd < d[i]) {
            maxd = d[i];
            x = i;
        }
    }
    bfs(x);
    maxd = 0;
    for(int i = 0; i < N; i++) {
        if(maxd < d[i]) maxd = d[i];
    }
    return maxd;
}

int main() {
    int s, t, w;
    cin >> N;
    for(int i = 1; i < N; i++) {
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    cout << diameter() << endl;
}
