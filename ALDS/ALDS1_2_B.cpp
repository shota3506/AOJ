//Selection Sort
#include <iostream>
#include <algorithm>

using namespace std;

int selectionSort(int A[], int n) {
    int count = 0;
    for(int i=0; i<n-1; i++) {
        int minj = i;
        for(int j=i+1; j<n; j++) {
            if(A[j] < A[minj]) minj = j;
        }
        if(i != minj) {
            swap(A[i], A[minj]);
            count++;
        }
    };
    return count;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    int count = selectionSort(A, n);

    for(int i=0; i<n-1; i++) cout << A[i] << " ";
    cout << A[n-1] << endl;
    cout << count << endl;

    return 0;
}