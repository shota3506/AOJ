//Disjoint Set: Union Find Tree
#include <iostream>
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

int main() {
    int n, q, com, x, y;
    cin >> n >> q;
    UnionFindTree S(n);
    for(int i = 0; i < q; i++) {
        cin >> com >> x >> y;
        if(com == 0) {
            S.unite(x, y);
        }
        else if(com == 1) {
            if(S.same(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}
