//Doubly Linked List
#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    int key;
    Node *prev, *next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    void insert(int key);
    void deleteKey(int key);
    void deleteFirst();
    void deleteLast();
    void trace();
private:
    void deleteNode(Node *x);
    Node *nil;
};

DoublyLinkedList::DoublyLinkedList() {
    nil = new Node;
    nil -> next = nil;
    nil -> prev = nil;
}

void DoublyLinkedList::insert(int key) {
    Node *x;
    x = new Node;
    x -> key = key;
    x -> next = (nil -> next);
    x -> prev = nil;
    nil -> next -> prev = x;
    nil -> next = x;
}

void DoublyLinkedList::deleteKey(int key) {
    Node *x = nil -> next;
    while(x != nil && x -> key != key) {
        x = x -> next;
    }
    deleteNode(x);
}

void DoublyLinkedList::deleteFirst() {
    deleteNode(nil -> next);
}

void DoublyLinkedList::deleteLast() {
    deleteNode(nil -> prev);
}

void DoublyLinkedList::deleteNode(Node *x) {
    if(x == nil) return;
    x -> prev -> next = x -> next;
    x -> next -> prev = x -> prev;
    delete x;
}

void DoublyLinkedList::trace() {
    Node *x = nil -> next;
    while(x != nil) {
        if(x -> prev != nil) cout << " ";
        cout << x -> key;
        x = x -> next;
    }
    cout << endl;
}


int main() {
    int n;
    DoublyLinkedList L;
    string opr;
    int key;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> opr;
        if(opr == "insert") {
            cin >> key;
            L.insert(key);
        }
        else if(opr == "delete") {
            cin >> key;
            L.deleteKey(key);
        }
        else if(opr == "deleteFirst") L.deleteFirst();
        else if(opr == "deleteLast") L.deleteLast();
    }
    L.trace();
}