#include <iostream>

using namespace std;

int main() {
    int N, A, cnt = 0, maxc = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> A;
        if(A == 1) cnt++;
        else {
            maxc = max(maxc, cnt);
            cnt = 0;
        }
    }
    maxc = max(maxc, cnt);

    cout << maxc + 1 << endl;
}