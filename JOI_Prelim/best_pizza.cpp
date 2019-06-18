//Best Pizza
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    int D[N];
    for(int i = 0; i < N; i++) {
        cin >> D[i];
    }

    sort(D, D + N, greater<int>());

    int cal = C, p = C / A;
    for(int i = 0; i < N; i++) {
        cal += D[i];
        if(cal / (A + B * (i + 1)) >= p) {
            p = cal / (A + B * (i + 1));
            continue;
        }
        break;
    }

    cout << p << endl;

    return 0;
}