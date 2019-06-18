//Binaty Tree
#include <iostream>

using namespace std;

static const int NIL = -1;

struct Node {
    int parent = NIL, left = NIL, right = NIL, sibling = NIL, degree = 0, depth = 0, height = 0;
};

void setDepth(Node N[], int u, int d) {
    N[u].depth = d;
    if(N[u].right != NIL) setDepth(N, N[u].right, d + 1);
    if(N[u].left != NIL) setDepth(N, N[u].left, d + 1);
}

void setHeight(Node N[], int u, int h) {
    if(N[u].height < h) N[u].height = h;
    if(N[u].parent != NIL) setHeight(N, N[u].parent, h + 1);
}

int main() {
    int n, id, left, right;
    cin >> n;
    Node N[n];
    for(int i = 0; i < n; i++) {
        cin >> id >> left >> right;
        N[id].degree = (left != NIL) + (right != NIL);
        if(left != NIL) {
            N[id].left = left;
            N[left].parent = id;
        }
        if(right != NIL) {
            N[id].right = right;
            N[right].parent = id;
        }
        if(left != NIL && right != NIL) {
            N[left].sibling = right;
            N[right].sibling = left;
        }
    }

    for(int i = 0; i < n; i++) {
        if(N[i].parent == NIL) setDepth(N, i, 0);
        if(N[i].degree == 0) setHeight(N, i, 0);
    }

    for(int i = 0; i < n; i++) {
        cout << "node " << i
             << ": parent = " << N[i].parent
             << ", sibling = " << N[i].sibling
             << ", degree = " << N[i].degree
             << ", depth = " << N[i].depth
             << ", height = " << N[i].height;
        if(N[i].parent == NIL) cout <<", root" << endl;
        else if(N[i].left == NIL && N[i].right == NIL) cout << ", leaf" << endl;
        else cout << ", internal node" << endl;
    }
}