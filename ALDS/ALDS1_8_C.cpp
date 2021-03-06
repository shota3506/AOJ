//Binary Search Tree III
#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node *parent = nullptr, *left = nullptr, *right = nullptr;

    Node(int key): key(key) {};
};

class Tree {
public:
    Node *root = nullptr;

    void insert(int k) {
        Node *x = root, *y = nullptr;
        while(x != nullptr) {
            y = x;
            if(k <= x->key) x = x->left;
            else x = x->right;
        }

        Node *z = new Node(k);
        z->parent = y;
        if(y == nullptr) root = z;
        else if(k <= y->key) y->left = z;
        else y->right = z;
    };

    Node* find(int k) {
        Node *x = root;
        while(x != nullptr && x->key != k) {
            if(k < x->key) x = x->left;
            else x = x->right;
        }
        return x;
    };

    Node* getMinimum(Node *u) {
        while(u->left != nullptr) u = u->left;
        return u;
    }

    void deleteNode(int k) {
        Node *x = find(k), *y = nullptr, *z = nullptr;
        if(x->left == nullptr || x->right == nullptr) y = x;
        else {
            y = getMinimum(x->right);
            x->key = y->key;
        }

        if(y->left != nullptr) z = y->left;
        else z = y->right;

        if(z != nullptr) z->parent = y->parent;

        if(y->parent == nullptr) root = z;
        else if(y->parent->left == y) y->parent->left = z;
        else y->parent->right = z;

        delete y;
    };
};

void inOrder(Node *u) {
    if(u == nullptr) return;
    inOrder(u->left);
    cout << " " << u->key;
    inOrder(u->right);
}

void preOrder(Node *u) {
    if(u == nullptr) return;
    cout << " " << u->key;
    preOrder(u->left);
    preOrder(u->right);
}

int main() {
    Tree T;

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string opr;
        int key;
        cin >> opr;
        if(opr == "insert") {
            cin >> key;
            T.insert(key);
        }
        if(opr == "find") {
            cin >> key;
            if(T.find(key) != nullptr) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        if(opr == "delete") {
            cin >> key;
            T.deleteNode(key);
        }
        if(opr == "print") {
            inOrder(T.root);
            cout << endl;
            preOrder(T.root);
            cout << endl;
        }
    }
}