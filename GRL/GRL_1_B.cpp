//Single Source Shortest Path (Negative Edges)
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Edge {
public:
    int s, t;
    long long d;
    Edge(int s, int t, long long d): s(s), t(t), d(d) {}
    bool operator < (const Edge e) const {return d < e.d;}
};

void bellmanFord(int r, int n, int m, vector<Edge> &E) {
    vector<long long> D(n, LONG_LONG_MAX);
    D[r] = 0;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m; j++) {
            Edge e = E[j];
            if(D[e.s] == LONG_LONG_MAX) continue;
            D[e.t] = min(D[e.t], D[e.s] + e.d);
        }
    }

    bool flg = false;
    for(int j=0; j<m; j++) {
        Edge e = E[j];
        if(D[e.s] == LONG_LONG_MAX) continue;
        if(D[e.t] > D[e.s] + e.d) flg = true;
    }

    if(flg) cout << "NEGATIVE CYCLE" << endl;
    else {
        for(int i=0; i<n; i++)  {
            if(D[i] == LONG_LONG_MAX) cout << "INF" << endl;
            else cout << D[i] << endl;
        }
    }
}

int main() {
    int n, m, r, s, t;
    long long d;
    vector<Edge> E;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++) {
        cin >> s >> t >> d;
        E.push_back(Edge(s, t, d));
    }

    bellmanFord(r, n, m,E);

    return 0;
}
