//Total Time
#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int t, x, y;
    t = A + B + C + D;
    x = t / 60;
    y = t % 60;
    cout << x << endl;
    cout << y << endl;

    return 0;
}