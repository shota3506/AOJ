//Refreshment Area
#include <iostream>

using namespace std;

static const int MAX = 100;

bool A[MAX][MAX];

int main() {
    int N, M, D;
    cin >> N >> M >> D;

    char a;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a;
            A[i][j] = a == '.';
        }
    }

    int cnt = 0, space;
    for(int i = 0; i < N; i++) {
        space = 0;
        for(int j = 0; j < M; j++) {
            if(A[i][j]) {
                space++;
                if(space >= D) cnt++;
            } else {
                space = 0;
            }
        }
    }

    for(int j = 0; j < M; j++) {
        space = 0;
        for(int i = 0; i < N; i++) {
            if(A[i][j]) {
                space++;
                if(space >= D) cnt++;
            } else {
                space = 0;
            }
        }
    }

    cout << cnt << endl;
}