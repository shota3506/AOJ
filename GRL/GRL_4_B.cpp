//Topological Sort
#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>> &G) {
    vector<int> indeg(n, 0);
    for(int s=0; s<n; s++)
        for(int t: G[s])
            indeg[t]++;

    queue<int> q;
    for(int i=0; i<n; i++)
        if(indeg[i] == 0) q.push(i);

    vector<int> ans;
    while(!q.empty()) {
        int s = q.front(); q.pop();
        ans.push_back(s);
        for(int t: G[s]) {
            if(--indeg[t] == 0) q.push(t);
        }
    }

    return ans;
}

int main() {
    int n, m, s, t;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }

    vector<int> ans = topologicalSort(n, G);

    for(auto a : ans) cout << a << endl;
}
