//Allocation
#include <iostream>
#include <climits>

using namespace std;

bool check(int w[], int n, int k, int p) {
    int cnt = 1;
    int margin = p;
    for(int i=0; i<n; i++) {
        if(w[i] > p) return false;
        if(margin >= w[i]) margin -= w[i];
        else {
            cnt++;
            margin = p - w[i];
        }
    }
    return cnt <= k;
}

int solve(int w[], int n, int k) {
    int  left = 0, right = INT_MAX, mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(check(w, n, k, mid)) right = mid;
        else left = mid+1;
    }
    return left;
}

int main() {
    int n, k;
    cin >> n >> k;
    int w[n];
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    cout << solve(w, n, k) << endl;
}
