//Unique Number
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N][3];
    for(int i = 0; i < N; i++) for(int j = 0; j < 3; j++)
            cin >> A[i][j];
    for(int k = 0; k < 3; k++) {
        for(int i = 0; i < N - 1; i++) {
            if(A[i][k] == 0) continue;
            int a = A[i][k];
            for(int j = i + 1; j < N; j++) {
                if(a == A[j][k]) {
                    A[i][k] = A[j][k] = 0;
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << (A[i][0] + A[i][1] + A[i][2]) << endl;
    }

    return 0;
}