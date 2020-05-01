//Insertion Sort
#include <iostream>

using namespace std;

void print(int A[], int n) {
    for(int i=0; i<n-1; i++) cout << A[i] << " ";
    cout << A[n-1] << endl;
}

void insertionSort(int A[], int n) {
    print(A, n);

    for(int i=1; i<n; i++) {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        print(A, n);
    }
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    insertionSort(A, n);

    return 0;
};
