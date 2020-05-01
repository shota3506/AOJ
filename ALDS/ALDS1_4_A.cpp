//Linear Search
#include <iostream>

using namespace std;

bool search(int S[], int n, int key) {
    int i = 0;
    while(i < n) {
        if(S[i] == key) break;
        i++;
    }
    return i != n;
}

int main() {
    int n, q;
    cin >> n;
    int S[n];
    for(int i=0; i<n; i++) cin >> S[i];
    cin >> q;

    int cnt = 0;
    for(int i=0; i<q; i++) {
        int t;
        cin >> t;
        if(search(S, n, t)) cnt++;
    }
    cout << cnt << endl;
}