//Diameter of a Tree
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
public:
    int t, w;
    Edge(int t, int w): t(t), w(w) {}
};

pair<int, int> bfs(int u, int n, vector<vector<Edge>> &G) {
    int v = u, length = 0;
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push(make_pair(u, 0));

    while(!q.empty()) {
        int s = q.front().first;
        int l = q.front().second;
        visited[s] = true;
        if(l > length) {v = s; length = l;}
        q.pop();
        for(auto e: G[s]) {
            if(visited[e.t]) continue;
            q.push(make_pair(e.t, e.w + l));
        }
    }
    return make_pair(v, length);
}

int diameter(int n, vector<vector<Edge>> &G) {
    pair<int, int> p = bfs(0, n ,G);
    int x = p.first;
    pair<int, int> q = bfs(x, n ,G);
    return q.second;
}

int main() {
    int n, s, t, w;
    cin >> n;
    vector<vector<Edge>> G(n);
    for(int i = 1; i < n; i++) {
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    cout << diameter(n, G) << endl;

    return 0;
}
