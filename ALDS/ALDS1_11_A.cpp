//Graph
#include <iostream>

using namespace std;

int main() {
    int n, u, k, v;
    cin >> n;
    int M[n+1][n+1];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
            M[i][j] = 0;

    for(int i = 0; i < n; i++) {
        cin >> u >> k;
        for(int j = 0; j < k; j++) {
            cin >> v;
            M[u][v] = 1;
        }
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n; j++)
            cout << M[i][j] << " ";
        cout << M[i][n] << endl;
    }
}
