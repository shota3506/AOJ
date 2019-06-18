//Bubble Sort
#include <iostream>
#include <algorithm>

using namespace std;

int BubbleSort(int A[], int N) {
    int count =0;
    for(int i = 0; i < N; i++) {
        for(int j = N - 1; j > 0; j--) {
            if(A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    int count = BubbleSort();

    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
}