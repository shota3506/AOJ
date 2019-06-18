//Christmas Party
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int score[N + 1], A[M];
    for(int i = 1; i < N + 1; i++){
        score[i] = 0;
    }
    for(int i = 0; i < M; i++) {
        cin >> A[i];
    }

    int b;
    for(int i = 0; i < M; i++) {
        for(int j = 1; j < N + 1; j++){
            cin >> b;
            if(b == A[i]) score[j]++;
            else score[A[i]]++;
        }
    }

    for(int i = 1; i < N + 1; i++){
        cout << score[i] << endl;
    }
}