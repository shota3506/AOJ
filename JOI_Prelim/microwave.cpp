//Microwave
#include <iostream>

using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    int T = 0;

    if(A < 0) {
        T += (0 - A) * C + D + B * E;
    } else {
        T += (B - A) * E;
    }

    cout << T << endl;
}