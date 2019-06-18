//Water Rate
#include <iostream>

using namespace std;

int main() {
    int A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;

    int x, y;
    x = A * P;
    y = max(B, B + D * (P - C));

    cout << min(x, y) << endl;
}