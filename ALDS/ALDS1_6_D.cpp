//The Number of Inversions
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Weight {
    int id = 0;
    int weight = 0;
    bool searched = false;
    bool operator < (const Weight &w) const {
        return weight < w.weight;
    }
};

int main() {
    int n, s = INT_MAX;
    cin >> n;
    Weight W[n];
    for(int i=0; i<n; i++) {
        cin >> W[i].weight;
        W[i].id = i;
        s = min(s, W[i].weight);
    }

    sort(W, W+n);

    int cost = 0;
    for(int i=0; i<n; i++) {
        if(W[i].searched) continue;
        int id = i, c = 0, size = 0;
        while(1) {
            W[id].searched = true;
            c += W[id].weight;
            id = W[id].id;
            size++;
            if(id == i) break;
        }
        if(size != 1)
            cost += c + min((size-2)*W[i].weight, W[i].weight+(size+1)*s);
    }
    cout << cost << endl;
}