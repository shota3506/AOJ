//Selecting Subjects
#include <iostream>

using namespace std;

int main() {
    int Scores[6];
    for(int i = 0; i < 6; i++) cin >> Scores[i];

    int s = 0, minv = 101;
    for(int i = 0; i < 4; i++) {
        s += Scores[i];
        minv = min(minv, Scores[i]);
    }
    s -= minv;
    minv = 101;
    for(int i = 4; i < 6; i++) {
        s += Scores[i];
        minv = min(minv, Scores[i]);
    }
    s -= minv;

    cout << s << endl;
}
