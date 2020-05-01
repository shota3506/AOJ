//Bubble Sort
#include <iostream>
#include <algorithm>

using namespace std;

int bubbleSort(int A[], int n) {
    int count =0;
    for(int i=0; i<n-1; i++) {
        for(int j=n-1; j>i; j--) {
            if(A[j] < A[j-1]) {
                swap(A[j-1], A[j]);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    int count = bubbleSort(A, n);

    for(int i=0; i<n-1; i++) cout << A[i] << " ";
    cout << A[n-1] << endl;
    cout << count << endl;

    return 0;
}