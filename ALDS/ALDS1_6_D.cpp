//The Number of Inversions
#include <iostream>
#include <vector>

using namespace std;

struct weight {
    int id;
    int weight;
    bool searched = false;
};

int partition(weight A[], int p, int r) {
    int x = A[r].weight;
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(x >= A[j].weight) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(weight A[], int p, int r) {
    if(p < r) {
        int x = partition(A, p, r);
        quickSort(A, p, x - 1);
        quickSort(A, x + 1, r);
    }
}


int main() {
    int n, s = 10000;
    cin >> n;
    weight W[n];
    for(int i = 0; i < n; i++) {cin >> W[i].weight; W[i].id = i; s = min(s, W[i].weight);}

    quickSort(W, 0, n - 1);

    int cost = 0;
    for(int i = 0; i < n; i++) {
        if(!W[i].searched) {
            int id = i, c = 0, size = 0;
            while(1) {
                W[id].searched = true;
                c += W[id].weight;
                size++;
                id = W[id].id;
                if(id == i) break;
            }
            if(size != 1) cost += (c + min((size - 2) * W[i].weight, W[i].weight + (size + 1) * s));
        }
    }
    cout << cost << endl;
}