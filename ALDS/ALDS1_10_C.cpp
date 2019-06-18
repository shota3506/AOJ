//Longest Common Subsequence
#include <iostream>
#include <string>

using namespace std;

static const int N = 1000;

int lcs(string X, string Y) {
    int c[N + 1][N + 1] = {};
    int maxl = 0, m = int(X.size()), n = int(Y.size());
    X = X;
    Y = Y;
    for(int i = 0; i < m + 1; i++) c[i][m] = 0;
    for(int j = 0; j < n + 1; j++) c[n][j] = 0;
    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(X[i] == Y[j]) c[i][j] = 1 + c[i + 1][j + 1];
            else c[i][j] = max(c[i][j + 1], c[i + 1][j]);
        }
    }
    return c[0][0];

}

int main() {
    string s1, s2;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
}