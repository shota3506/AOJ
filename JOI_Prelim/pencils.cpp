#include <iostream>

using namespace std;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    int x = (N + A - 1) / A * B;
    int y = (N + C - 1) / C * D;

    cout << min(x, y) << endl;
}