//Soccer
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, a, b, c, d;
    vector<int> v;
    cin >> N;
    int S[N + 1];
    for(int i = 1; i < N + 1; i++) S[i] = 0;
    for(int i = 0; i < (N * (N - 1) / 2); i++) {
        cin >> a >> b >> c >> d;
        if(c > d) S[a] += 3;
        else if(c < d) S[b] += 3;
        else {S[a]++; S[b]++;}
    }
    for(int i = 1; i < N + 1; i++) {
        v.push_back(S[i]);
    }

    sort(v.begin(), v.end());

    for(int i = 1; i < N + 1; i++) {
        cout << 1 + int(distance(upper_bound(v.begin(), v.end(), S[i]), v.end())) << endl;
    }
}