//Binaty Tree
#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX = 10000;
static const int NIL = -1;

struct Node {
    int parent = NIL, left = NIL, right = NIL;
};

Node N[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d) {
    if(u == NIL) return;
    D[u] = d;
    setDepth(N[u].left, d+1);
    setDepth(N[u].right, d+1);
}

int setHeight(int u) {
    int h1 = 0, h2 = 0;
    if(N[u].left != NIL)
        h1 = setHeight(N[u].left) + 1;
    if(N[u].right != NIL)
        h2 = setHeight(N[u].right) + 1;
    H[u] = max(h1, h2);
    return H[u];
}

int getDegree(int u) {
    return (N[u].left != NIL) + (N[u].right != NIL);
}

int getSibling(int u) {
    if(N[u].parent == NIL) return NIL;
    if(N[N[u].parent].left != u && N[N[u].parent].left != NIL)
        return N[N[u].parent].left;
    if(N[N[u].parent].right != u && N[N[u].parent].right != NIL)
        return N[N[u].parent].right;
    return NIL;
}

int main() {
    int id, left, right;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> id >> left >> right;
        N[id].left = left;
        N[id].right = right;
        if(left != NIL) N[left].parent = id;
        if(right != NIL) N[right].parent = id;
    }

    int root;
    for(int i=0; i<n; i++)
        if(N[i].parent == NIL) root = i;

    setDepth(root, 0);
    setHeight(root);

    for(int i = 0; i < n; i++) {
        cout << "node " << i
             << ": parent = " << N[i].parent
             << ", sibling = " << getSibling(i)
             << ", degree = " << getDegree(i)
             << ", depth = " << D[i]
             << ", height = " << H[i];
        if(N[i].parent == NIL) cout <<", root" << endl;
        else if(getDegree(i) == 0) cout << ", leaf" << endl;
        else cout << ", internal node" << endl;
    }
}