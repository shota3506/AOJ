//Minimum Spanning Tree
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class DisjointSet {
public:
    vector<int> rank, p;
    DisjointSet(int size);
    void makeSet(int x);
    void unite(int x, int y);
    void link(int x, int y);
    int findSet(int x);
};

DisjointSet::DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    for(int i = 0; i < size; i++) makeSet(i);
}

void DisjointSet::makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
}

void DisjointSet::unite(int x, int y) {
    link(findSet(x), findSet(y));
}

void DisjointSet::link(int x, int y) {
    if(rank[x] > rank[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
}

int DisjointSet::findSet(int x) {
    if(x != p[x]) {
        p[x] = findSet(p[x]);
    }
    return p[x];
}

struct Edge {
public:
    int s, t, c;
    Edge(int s, int t, int c): s(s), t(t), c(c) {}
    bool operator < ( const Edge &e ) const {
        return c < e.c;
    }
};

int kruskal(int N, vector<Edge> E) {
    int t = 0;
    sort(E.begin(), E.end());
    DisjointSet D = DisjointSet(N);
    for(auto itr = E.begin(); itr != E.end(); itr++) {
        if(D.findSet(itr -> s) != D.findSet(itr -> t)) {
            D.unite(itr -> s, itr -> t);
            t += itr -> c;
        }
    }
    return t;
}

int main() {
    int N, M, s, t, c;
    vector<Edge> E;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> s >> t >> c;
        E.push_back(Edge(s, t, c));
    }

    cout << kruskal(N, E) << endl;
}