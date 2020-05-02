//Longest Common Subsequence
#include <iostream>
#include <string>

using namespace std;

static const int N = 1000;

int lcs(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    int dp[l1+1][l2+1];
    for(int i=0; i<l1+1; i++) dp[i][0] = 0;
    for(int j=0; j<l2+1; j++) dp[0][j] = 0;

    for(int i=1; i<l1+1; i++) {
        for(int j=1; j<l2+1; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[l1][l2];
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
