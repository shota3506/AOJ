//Maximum Heap
#include <iostream>

using namespace std;

int parent(int i) {return i/2;}
int left(int i) {return 2*i;}
int right(int i) {return 2*i+1;}

void maxHeapify(int A[], int H, int i) {
    int l = left(i), r = right(i);

    int largest = i;
    if(l <= H && A[l] > A[largest]) largest = l;
    if(r <= H && A[r] > A[largest]) largest = r;

    if(largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, H, largest);
    }
}

void buildMaxHeap(int A[], int H) {
    for(int i=H/2; i>0; i--) maxHeapify(A, H, i);
}

int main() {
    int H;
    cin >> H;
    int A[H+1];
    for(int i=1; i<H+1; i++) cin >> A[i];

    buildMaxHeap(A, H);

    for(int i=1; i<H+1; i++) cout << " " << A[i];
    cout << endl;
}
