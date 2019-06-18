//Tile
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll N, K, M;
    cin >> N >> K;
    M = (N + 1) / 2;
    ll x, y;
    for(int i = 0; i < K; i++) {
        cin >> x >> y;
        if(x > M) x = N - x + 1;
        if(y > M) y = N - y + 1;
        if(min(x, y) % 3 == 1) cout << 1 << endl;
        else if(min(x, y) % 3 == 2) cout << 2 << endl;
        else cout << 3 << endl;
    }

    return 0;
}