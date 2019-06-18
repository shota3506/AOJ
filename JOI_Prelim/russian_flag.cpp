//Russian Flag
#include <iostream>
#include <climits>

using namespace std;

enum COLOR {
    WHITE = 0,
    BLUE = 1,
    RED = 2
};

int main() {
    int N, M;
    cin >> N >> M;
    int Flag[N][3];
    char c;
    for(int i = 0; i < N; i++) {
        for(int c = 0; c < 3; c++) Flag[i][c] = 0;

        for(int j = 0; j < M; j++) {
            cin >> c;
            if(c == 'W') Flag[i][WHITE]++;
            if(c == 'B') Flag[i][BLUE]++;
            if(c == 'R') Flag[i][RED]++;
        }
    }

    for(int c = 0; c < 3; c++) {
        for(int i = 1; i < N; i++) {
            Flag[i][c] += Flag[i - 1][c];
        }
    }

    int minc = INT_MAX;
    for(int i = 1; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            int cost = 0;
            cost += i * M - Flag[i - 1][WHITE];
            cost += (j - i) * M - (Flag[j - 1][BLUE] - Flag[i - 1][BLUE]);
            cost += (N - j) * M - (Flag[N - 1][RED] - Flag[j - 1][RED]);
            minc = min(minc, cost);
        }
    }

    cout << minc << endl;
}