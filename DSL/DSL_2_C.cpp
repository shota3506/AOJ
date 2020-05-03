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

class Node {
public:
    int location = NIL;
    Node *left = nullptr, *right = nullptr;

    Node(int location): location(location) {};
};

class Tree {
public:
    Node *root = nullptr;

    Tree() {root = make2DTree(0, n, 0);};

    Node* make2DTree(int l, int r, int depth) {
        if(l >= r) return nullptr;
        int mid = (l + r) / 2;
        if(depth % 2 == 0) sort(P+l, P+r, lessX);
        else sort(P+l, P+r, lessY);

        Node *node = new Node(mid);
        node->left = make2DTree(l, mid, depth+1);
        node->right = make2DTree(mid+1, r, depth+1);
        return node;
    }

    void find(Node *node, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans) {
        if(node == nullptr) return;

        int x = P[node->location].x, y = P[node->location].y;
        if(x >= sx && x <= tx && y >= sy && y <= ty) ans.push_back(P[node->location]);

        if(depth % 2 == 0) {
            if(x >= sx) find(node->left, sx, tx, sy, ty, depth+1, ans);
            if(x <= tx) find(node->right, sx, tx, sy, ty, depth+1, ans);
        }
        else {
            if(y >= sy) find(node->left, sx, tx, sy, ty, depth+1, ans);
            if(y <= ty) find(node->right, sx, tx, sy, ty, depth+1, ans);
        }
    }
};

int main() {
    int q, x, y, sx, tx, sy, ty;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        P[i].id = i; P[i].x = x; P[i].y = y;
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
