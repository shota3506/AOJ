//Shell Sort
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int m;
std::vector<int> G;

void insertionSort(int A[], int n, int g) {
    for(int i=g; i<n; i++) {
        int key = A[i];
        int j = i - g;
        while(j>=0 && A[j] > key) {
            A[j+g] = A[j];
            j-=g;
            cnt++;
        }
        A[j+g] = key;
    }
}

void shellSort(int A[], int n) {
    int h = 1;
    while(h <= n) {
        G.insert(G.begin(), h);
        h = 3 * h + 1;
    }
    m = int(G.size());

    for(int i = 0; i < m; i++) insertionSort(A, n, G[i]);
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    shellSort(A, n);

    cout << m << endl;
    for(int i=0; i<m-1; i++) cout << G[i] << " ";
    cout << G[m-1] << endl;
    cout << cnt << endl;
    for(int i = 0; i < n; i++) cout << A[i] << endl;

    return 0;
}