//Maximum Profit
#include <iostream>
#include <algorithm>

using namespace std;
static const int MAX =200000;

int main() {
    int n;
    cin >> n;
    int R[n];
    for(int i = 0; i < n; i++) cin >> R[i];

    int max_dif;
    int minv = R[0];
    for(int i = 1; i < n; i++) {
        if(i == 1)
            max_dif = R[i] - minv;
        else
            max_dif = max(max_dif, R[i] - minv);
        minv = min(minv, R[i]);
    }
    cout << max_dif << endl;
}