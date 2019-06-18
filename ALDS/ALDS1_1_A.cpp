//Insertion Sort
#include <iostream>
#include <algorithm>

using namespace std;

void trace(int A[], int N) {
    for(int i = 0; i < N - 1; i++) cout << A[i] << " ";
    cout << A[N-1];
    cout << endl;
}

void InsertionSort(int A[], int N) {
    for(int i = 1; i < N; i++) {
        int key = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        trace(A, N);
    }
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    trace(A, N);
    InsertionSort(A, N);
}
