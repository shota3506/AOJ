//Binary Search Tree II
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *parent = nullptr, *left = nullptr, *right = nullptr;
    explicit Node(int key) : key(key){}
};

class Tree {
public:
    void insert(int key);
    Node * find(int key);
    Node *root = nullptr;
};

void Tree::insert(int key) {
    Node *x = root;
    Node *y = nullptr;
    auto *n = new Node(key);
    while(x != nullptr) {
        y = x;
        if(key < x -> key) x = x -> left;
        else x = x -> right;
    }
    if(y == nullptr) {
        root = n;
    }
    else {
        n -> parent = y;
        if(key < y -> key) y -> left = n;
        else y -> right = n;
    }
}

Node * Tree::find(int key) {
    Node *x = root;
    while(x != nullptr) {
        if(x -> key == key) break;
        else if(key < x -> key) x = x -> left;
        else x = x -> right;
    }
    return x;
}

void inOrder(Node *N) {
    if(N == nullptr) return;
    inOrder(N -> left);
    cout << " " << (N -> key);
    inOrder(N -> right);
}

void preOrder(Node *N) {
    if(N == nullptr) return;
    cout << " " << (N -> key);
    preOrder(N -> left);
    preOrder(N -> right);
}


int main() {
    Tree T;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
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
        if(opr == "print") {
            inOrder(T.root);
            cout << endl;
            preOrder(T.root);
            cout << endl;
        }
    }
}