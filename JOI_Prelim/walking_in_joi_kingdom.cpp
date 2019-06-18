//Walking in JOI Kingdom
#include <iostream>

using namespace std;
typedef long long ll;

static const int MAX = 100000;

enum DIRECTION {
    EAST = 1,
    WEST = 2
};

struct House {
    ll a;
    int d;
    House() {}
    House(ll a, int d): a(a), d(d) {}
};

int N, Q;
ll T;
House H[MAX + 1];
ll A[MAX + 1];
bool Traced[MAX + 1];

ll trace(int target) {
    if(Traced[target]) return A[target];
    ll a;
    if(H[target].d == EAST) {
        if(target == N) a = H[target].a + T;
        else {
            int neighbor = target + 1;
            if(H[neighbor].d == EAST) {
                if(H[neighbor].a - H[target].a >= T) {
                    a = H[target].a + T;
                } else {
                    a = min(H[target].a + T, trace(neighbor));
                }
            }
            else a = min(H[target].a + T, (H[target].a + H[neighbor].a) / 2);
        }
    } else if(H[target].d == WEST) {
        if(target == 1) a = H[target].a - T;
        else {
            int neighbor = target - 1;
            if(H[neighbor].d == WEST) {
                if(H[target].a - H[neighbor].a >= T) {
                    a = H[target].a - T;
                } else {
                    a = max(H[target].a - T, trace(neighbor));
                }
            }
            else a = max(H[target].a - T, (H[target].a + H[neighbor].a) / 2);
        }
    }
    Traced[target] = true;
    A[target] = a;
    return a;
}

int main() {
    scanf("%d %lld %d", &N, &T, &Q);

    ll a;
    int d;
    for(int i = 1; i < N + 1; i++) {
        scanf("%lld %d", &a, &d);
        H[i] = House(a, d);
        Traced[i] = false;
    }

    int target;
    for(int i = 0; i < Q; i++) {
        scanf("%d", &target);
        cout << trace(target) << endl;
    }
}