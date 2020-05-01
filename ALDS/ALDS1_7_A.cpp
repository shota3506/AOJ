//Rooted Trees
#include <iostream>

using namespace std;

struct Node {
    int p = -1, l = -1, r = -1, d = 0;
};

void setDepth(Node N[], int u, int d) {
    N[u].d = d;
    if(N[u].r != -1) setDepth(N, N[u].r, d);
    if(N[u].l != -1) setDepth(N, N[u].l, d + 1);
}

int main() {
    int n;
    cin >> n;
    Node N[n];
    for(int i=0; i<n; i++) {
        int id, k;
        cin >> id >> k;
        if(k > 0) {
            int c[k];
            for(int j=0; j<k; j++) cin >> c[j];
            N[id].l = c[0];
            for(int j=0; j<k; j++) {
                N[c[j]].p = id;
                if(k - j > 1) N[c[j]].r = c[j + 1];
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(N[i].p == -1) {
            setDepth(N, i, 0);
            break;
        }
    }

    for(int i=0; i<n; i++) {
        cout << "node " << i << ": parent = " << N[i].p << ", depth = " << N[i].d << ", ";
        if(N[i].p == -1) cout <<"root, ";
        else if(N[i].l == -1) cout << "leaf, ";
        else cout << "internal node, ";
        int n = N[i].l;
        cout << "[";
        while(n != -1) {
            cout << n;
            n = N[n].r;
            if(n != -1) cout << ", ";
        }
        cout << "]" << endl;
    }
}