//Reconstruction of a Tree
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, pos;
vector<int> pre, in, post;

void solve(int l, int r) {
    if(l >= r) return;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    solve(l, m);
    solve(m+1, r);
    post.push_back(root);
}

int main() {
    cin >> n;

    int k;
    for(int i=0; i<n; i++) {
        cin >> k;
        pre.push_back(k);
    }
    for(int i=0; i<n; i++) {
        cin >> k;
        in.push_back(k);
    }

    pos = 0;
    solve(0, n);

    for(int i=0; i<n-1; i++) cout << post[i] << " ";
    cout << post[n-1] << endl;
}