//Exhaustive Search
#include <iostream>

using namespace std;

bool solve(int A[], int n, int p, int t) {
    if(A[p] == t) return true;
    else if(n-1 <= p) return false;
    else if(A[p] > t) return solve(A, n, p+1, t);
    else return solve(A, n, p+1, t) || solve(A, n, p+1, t-A[p]);
}

int main() {
    int n, q;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    cin >> q;

    int m;
    for(int i = 0; i < q; i++) {
        cin >> m;
        if(solve(A, n, 0, m)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
