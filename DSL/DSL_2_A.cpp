//Segment Tree
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int INIT = 2147483647;

class SegmentTree {
public:
    explicit SegmentTree(int size);
    void update(int i, int x);
    int find(int s, int t);
    int query(int s, int t, int k, int l, int r);
private:
    int n;
    vector<int> p;
};

SegmentTree::SegmentTree(int size) {
    n = 1;
    while(n<size) n*=2;
    p = vector<int>(2*n-1, INIT);
}

void SegmentTree::update(int i, int x) {
    int s = i+n-1;
    p[s] = x;
    while(s > 0) {
        s = (s-1)/2;
        p[s] = min(p[2*s+1], p[2*s+2]);
    }
}

int SegmentTree::find(int s, int t) {
    return query(s, t, 0, 0, n);
}

int SegmentTree::query(int s, int t, int k, int l, int r) {
    if(r <= s || t <= l) return INIT;
    if(s <= l && r <= t) return p[k];
    int lv = query(s, t, 2*k+1, l, (l+r)/2);
    int rv = query(s, t, 2*k+2, (l+r)/2, r);
    return min(lv, rv);
}

int main() {
    int n, q, com, x, y;
    cin >> n >> q;
    SegmentTree S(n);

    for(int i = 0; i < q; i++) {
        cin >> com >> x >> y;
        if(com == 0) {
            S.update(x, y);
        }
        else if(com == 1) {
            cout << S.find(x, y+1) << endl;
        }
    }
}