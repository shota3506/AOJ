//Homework
#include <iostream>

using namespace std;

int main() {
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    int x = (A + C - 1) / C;
    int y = (B + D - 1) / D;
    cout << (L - max(x, y)) << endl;

    return 0;
}