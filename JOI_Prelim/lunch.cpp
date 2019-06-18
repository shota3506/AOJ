//Lunch
#include <iostream>

using namespace std;

int main() {
    int p, j, minp = 10000, minj = 10000;
    for(int i = 0; i < 3; i++) {
        cin >> p;
        minp = min(minp, p);
    }
    for(int i = 0; i < 2; i++) {
        cin >> j;
        minj = min(minj, j);
    }

    cout << (minp + minj - 50) << endl;

    return 0;
}