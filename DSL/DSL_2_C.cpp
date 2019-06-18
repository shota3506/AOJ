//Range Search
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int NIL = -1;
static const int MAX = 1000000;

class Point {
public:
    int id, x, y;
    Point() {}
    Point(int id, int x, int y): id(id), x(x), y(y) {}
    bool operator < ( const Point &p) const {
        return id < p.id;
    }
    void print() {
        printf("%d\n", id);
    }
};

bool lessX(const Point &p1, const Point &p2) {return p1.x < p2.x;}
bool lessY(const Point &p1, const Point &p2) {return p1.y < p2.y;}

int n;
Point P[MAX];

struct Node {
public:
    int location = NIL;
    Node * p = nullptr, * l = nullptr, * r = nullptr;
};

class Tree {
public:
    Node * root;
    Tree();
    Node * make2DTree(int l, int r, int depth);
    void find(Node * node, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans);
};

Tree::Tree() {
    root = make2DTree(0, n, 0);
}

Node * Tree::make2DTree(int l, int r, int depth) {
    if(l >= r) return nullptr;
    int mid = (l + r) / 2;
    if(depth % 2 == 0) sort(P + l, P + r, lessX);
    else sort(P + l, P + r, lessY);

    auto node = new Node;
    node -> location = mid;
    node -> l = make2DTree(l, mid, depth + 1);
    node -> r = make2DTree(mid + 1, r, depth + 1);
    return node;
}

void Tree::find(Node * node, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans) {
    int x = P[node -> location].x;
    int y = P[node -> location].y;
    if(sx <= x && x <= tx && sy <= y && y <= ty) ans.push_back(P[node -> location]);
    if(depth % 2 == 0) {
        if(node -> l != nullptr && sx <= P[node -> location].x) find(node -> l, sx,tx, sy, ty, depth + 1, ans);
        if(node -> r != nullptr && P[node -> location].x <= tx) find(node -> r, sx,tx, sy, ty, depth + 1, ans);
    }
    else if(depth % 2 != 0) {
        if(node -> l != nullptr && sy <= P[node -> location].y) find(node -> l, sx,tx, sy, ty, depth + 1, ans);
        if(node -> r != nullptr && P[node -> location].y <= ty) find(node -> r, sx,tx, sy, ty, depth + 1, ans);
    }
}

int main() {
    int q, x, y, sx, tx, sy, ty;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        P[i].id = i;
        P[i].x = x;
        P[i].y = y;
    }
    Tree T;

    scanf("%d", &q);
    vector<Point> ans;
    for(int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear();
        T.find(T.root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for(auto a: ans) {
            a.print();
        }
        cout << endl;
    }
}