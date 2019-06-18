//Reconstruction of a Tree
#include <iostream>

using namespace std;

int c = 1;

void solve(int A[], int B[], int p, int q, int n) {
    int r = 0;
    for(int i = 0; i < n; i++) {
        if(B[q + i] == A[p]) {r = i; break;}
    }
    if(r > 0) {
        solve(A, B, p + 1, q, r);
    }
    if(r + 1 < n) {
        solve(A, B, p + r + 1, q + r + 1, n - 1- r);
    }
    if(c != 0) c--;
    else cout << " ";
    cout <<  A[p];
}



int main() {
    int n;
    cin >> n;

    int A[n], B[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    solve(A, B, 0, 0, n);

    cout << endl;
}

