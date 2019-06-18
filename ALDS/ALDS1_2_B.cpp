//Selection Sort
#include <iostream>
#include <algorithm>

using namespace std;

int SelectionSort(int A[], int N) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        int mini = i;
        for (int j = i; j < N; j++) {
            if(A[mini] > A[j]) mini = j;
        }
        if(i != mini) {
            swap(A[i], A[mini]);
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    int count = SelectionSort(A, N);

    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
}