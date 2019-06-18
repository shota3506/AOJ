//Stable Sort
#include <iostream>
#include <algorithm>

using namespace std;

struct Card {
    char suit;
    int value;
};

void BubbleSort(Card C[], int N) {
    for(int i = 0; i < N; i++) {
        for(int j = N - 1; j > 0; j--) {
            if(C[j].value < C[j-1].value) {
                swap(C[j], C[j-1]);
            }
        }
    }
}

void SelectionSort(Card C[], int N) {
    for(int i = 0; i < N; i++) {
        int mini = i;
        for (int j = i; j < N; j++) {
            if(C[mini].value > C[j].value) mini = j;
        }
        if(i != mini) {
            swap(C[i], C[mini]);
        }
    }
}

bool isStable(Card C1[], Card C2[], int N) {
    bool stable = true;
    for(int i = 0; i < N && stable; i++) {
        if(C1[i].suit != C2[i].suit) stable = false;
    }
    return stable;
}

int main() {
    int N;
    cin >> N;
    Card C1[N], C2[N];
    for(int i = 0; i < N; i++) cin >> C1[i].suit >> C1[i].value;
    for(int i = 0; i < N; i++) C2[i] = C1[i];

    BubbleSort(C1, N);
    SelectionSort(C2, N);

    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << C1[i].suit << C1[i].value;
    }
    cout << endl;
    cout << "Stable" << endl;

    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << C2[i].suit << C2[i].value;
    }
    cout << endl;
    if(isStable(C1, C2, N)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
}