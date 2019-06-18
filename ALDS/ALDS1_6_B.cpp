//Partition
#include <iostream>

using namespace std;

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(x >= A[j]) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];

    int x = partition(A, 0, n - 1);

    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        if(i == x) {
            cout << "[" << A[i] << "]";
        }
        else cout << A[i];
    }
    cout << endl;
}