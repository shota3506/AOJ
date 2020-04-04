//Disjoint Set: Union Find Tree
#include <iostream>
#include <vector>

using namespace std;

class UnionFindTree {
public:
    explicit UnionFindTree(int size);
    void unite(int x, int y);
    bool same(int x, int y);
    int findSet(int x);
private:
    vector<int> p, rank;
};

UnionFindTree::UnionFindTree(int size) {
    p = vector<int>(size);
    rank = vector<int>(size, 0);
    for(int i=0; i<size; i++) p[i] = i;
}

void UnionFindTree::unite(int x, int y) {
    int sx = findSet(x), sy = findSet(y);
    if(rank[sx] > rank[sy]) {
        p[sy] = sx;
    }
    else {
        p[sx] = sy;
        if(rank[sx] == rank[sy]) rank[sy]++;
    }
}

bool UnionFindTree::same(int x, int y) {
    return findSet(x) == findSet(y);
}

int UnionFindTree::findSet(int x) {
    if(x != p[x]) p[x] = findSet(p[x]);
    return p[x];
}

int main() {
    int n, q, com, x, y;
    cin >> n >> q;
    UnionFindTree S(n);
    for(int i = 0; i < q; i++) {
        cin >> com >> x >> y;
        if(com == 0) S.unite(x, y);
        else if(com == 1) {
            if(S.same(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}