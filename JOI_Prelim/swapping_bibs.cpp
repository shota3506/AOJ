//Swapping Bibs
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int A[N], a;
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int k = 1; k < M + 1; k++) {
        int i = 0;
        while(i != N - 1) {
            if(A[i] % k > A[i + 1] % k) swap(A[i], A[i + 1]);
            i++;
        }
    }

    for(int i = 0; i < N; i++) cout << A[i] << endl;
}