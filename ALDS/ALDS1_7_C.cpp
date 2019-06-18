//Tree Walk
#include <iostream>

using namespace std;

static const int NIL = -1;

struct Node {
    int parent = NIL, left = NIL, right = NIL;
};

void preOrder(Node N[], int r) {
    cout << " " << r;
    if(N[r].left != NIL) preOrder(N, N[r].left);
    if(N[r].right != NIL) preOrder(N, N[r].right);
}

void inOrder(Node N[], int r) {
    if(N[r].left != NIL) inOrder(N, N[r].left);
    cout << " " << r;
    if(N[r].right != NIL) inOrder(N, N[r].right);
}

void postOrder(Node N[], int r) {
    if(N[r].left != NIL) postOrder(N, N[r].left);
    if(N[r].right != NIL) postOrder(N, N[r].right);
    cout << " " << r;
}


int main() {
    int n, id, left, right;
    cin >> n;
    Node N[n];
    for(int i = 0; i < n; i++) {
        cin >> id >> left >> right;
        if (left != NIL) {
            N[id].left = left;
            N[left].parent = id;
        }
        if (right != NIL) {
            N[id].right = right;
            N[right].parent = id;
        }
    }

    int r;
    for(int i = 0; i < n; i++) {if(N[i].parent == NIL) {r = i; break;}}

    cout << "Preorder" << endl;
    preOrder(N, r);
    cout << endl;
    cout << "Inorder" << endl;
    inOrder(N, r);
    cout << endl;
    cout << "Postorder" << endl;
    postOrder(N, r);
    cout << endl;
}
