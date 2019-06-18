//Linear Search
#include <iostream>

using namespace std;

bool search(int S[], int n, int key) {
    int left = 0;
    int right = n;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(S[mid] == key) return true;
        else if(S[mid] > key) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

int main() {
    int n, q;
    cin >> n;
    int S[n + 1];
    for(int i = 0; i < n; i++) cin >> S[i];
    cin >> q;

    int cnt = 0;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(search(S, n, t)) cnt++;
    }
    cout << cnt << endl;
}