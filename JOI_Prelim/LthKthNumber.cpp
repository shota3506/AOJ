//LthKthNumber
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

static const int MAX = 200000;

int A[MAX];
ll N, K, L;

bool check(ll num) {
    ll cnt  = 0, kcnt = 0;
    ll r = 0;
    for(int l = 0; l < N; l++) {
        while(kcnt < K && r < N) {
            if(A[r++] <= num) kcnt++;
        }
        if(kcnt == K) cnt += N - r + 1;
        if(A[l] <= num) kcnt--;
    }
    return cnt >= L;
}

int main() {
    cin >> N >> K >> L;
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    ll left = 1, right = N, mid;

    while(left < right) {
        mid = (left + right) / 2;
        if(check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}