//Allocation
#include <iostream>

using namespace std;

int check(int w[], int n, int p) {
    int k = 1;
    int margin = p;
    for(int i = 0; i < n; i++) {
        if(w[i] > p) return n + 1;
        margin -= w[i];
        if(margin < 0) {
            margin = p - w[i];
            k++;
        }
    }
    return k;
}

int solve(int w[], int n, int k) {
    long int mid, left = 0, right = 100000 * 100000;
    while(right - left > 1) {
        mid = (left + right) / 2;
        int x = check(w, n, mid);
        if(k >= x) right = mid;
        else if(k < x) left = mid;
    }
    return int(right);
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