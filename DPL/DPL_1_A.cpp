//Coin Chaining Problem
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int C[m];
    for(int i = 0; i < m; i++) cin >> C[i];

    sort(C, C + m);

    int T[m][n + 1];

    for(int i=0; i<m; i++) {
        T[i][0] = 0;
        for(int j=1; j<n+1; j++) {
            if(i == 0) T[i][j] = j / C[i];
            else {
                if(j - C[i] < 0) T[i][j] = T[i-1][j];
                else T[i][j] = min(T[i-1][j], 1 + T[i][j-C[i]]);
            }
        }
    }

    cout << T[m - 1][n] << endl;

    return 0;
}
