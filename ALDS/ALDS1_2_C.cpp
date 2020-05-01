//Stable Sort
#include <iostream>
#include <algorithm>

using namespace std;

struct Card {
    char suit;
    int value;
};

void print(Card C[], int n) {
    for(int i=0; i<n-1; i++) cout << C[i].suit << C[i].value << " ";
    cout << C[n-1].suit << C[n-1].value << endl;
}

void bubbleSort(Card C[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=n-1; j>i; j--) {
            if(C[j].value < C[j-1].value)
                swap(C[j-1], C[j]);
        }
    }
}

void selectionSort(Card C[], int n) {
    for(int i=0; i<n-1; i++) {
        Card key = C[i];
        int minj = i;
        for(int j=i+1; j<n; j++) {
            if(C[j].value < C[minj].value)
                minj = j;
        }
        if(i != minj) swap(C[i], C[minj]);
    }
}

bool isStable(Card C1[], Card C2[], int n) {
    for(int i=0; i<n; i++)
        if(C1[i].suit != C2[i].suit) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    Card C1[n], C2[n];
    for(int i=0; i<n; i++) cin >> C1[i].suit >> C1[i].value;
    for(int i=0; i<n; i++) C2[i] = C1[i];

    bubbleSort(C1, n);
    selectionSort(C2, n);

    print(C1, n);
    cout << "Stable" << endl;
    print(C2, n);
    if(isStable(C1, C2, n)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    return 0;
}