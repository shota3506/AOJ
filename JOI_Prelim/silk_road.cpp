//Silk Road
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int D[N], C[M], Fatigue[N + 1][M - N + 1];
    for(int i = 0; i < N; i++) cin >> D[i];
    for(int i = 0; i < M; i++) cin >> C[i];

    for(int i = 0; i < N + 1; i++) {
        for(int j = 0; j < M - N + 1; j++) {
            Fatigue[i][j] = INT_MAX;
        }
    }
    Fatigue[0][0] = 0;


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M - N + 1; j++) {
            if(j != M - N) Fatigue[i][j + 1] = min(Fatigue[i][j + 1], Fatigue[i][j]);
            Fatigue[i + 1][j] = min(Fatigue[i + 1][j], Fatigue[i][j] + D[i] * C[i + j]);
        }
    }

    int minf = INT_MAX;
    for(int j = 0; j < M - N + 1; j++) {
        minf = min(minf, Fatigue[N][j]);
    }

    cout << minf << endl;

    return 0;
}