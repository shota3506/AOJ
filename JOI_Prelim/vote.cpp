//Vote
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int A[N], V[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        V[i] = 0;
    }

    int b;
    for(int i = 0; i < M; i++) {
        cin >> b;
        for(int j = 0; j < N; j++) {
            if(A[j] <= b) {
                V[j]++;
                break;
            }
        }
    }

    int c = 0, maxv = V[0];
    for(int i = 1; i < N; i++) {
        if(V[i] > maxv) {
            maxv = V[i];
            c = i;
        }
    }

    cout << (c + 1) << endl;
}