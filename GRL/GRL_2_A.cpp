//Minimum Spanning Tree
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class UnionFindTree {
private:
    vector<int> p, rank;
public:
    UnionFindTree(int size) {
        p = vector<int>(size);
        rank = vector<int>(size,0);
        for(int i=0; i<size; i++) p[i] = i;
    }

    int findSet(int x) {
        if(p[x] != x) p[x] = findSet(p[x]);
        return p[x];
    }

    void unite(int x, int y) {
        int sx = findSet(x), sy = findSet(y);
        if(rank[sx] > rank[sy]) p[sy] = sx;
        else {
            p[sx] = sy;
            if(rank[sx] == rank[sy]) rank[sx]++;
        }
    }

    bool same(int x, int y) {
        return findSet(x) == findSet(y);
    }
};

class Edge {
public:
    int s, t, c;
    Edge(int s, int t, int c): s(s), t(t), c(c) {}
    bool operator < (const Edge e) const {return c < e.c;}
};

int kruskal(int n, vector<Edge> &E) {
    UnionFindTree ut(n);

    sort(E.begin(), E.end());
    int d = 0;
    for(auto e: E) {
        if(ut.same(e.s, e.t)) continue;
        d += e.c;
        ut.unite(e.s, e.t);
    }
    return d;
}

int main() {
    int n, m, s, t, c;
    vector<Edge> E;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> t >> c;
        E.push_back(Edge(s, t, c));
    }

    cout << kruskal(n, E) << endl;

    return 0;
}
