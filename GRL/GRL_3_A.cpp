//Articulation Point
#include <iostream>
#include <vector>
#include <set>

using namespace std;

static const int MAX = 100000;
static const int NIL = -1;

int timer;
int prenum[MAX], parent[MAX], lowest[MAX];
bool visited[MAX];

void dfs(int current, int prev, int n, vector<vector<int>> &G) {
    visited[current] = true;
    prenum[current] = lowest[current] = timer++;

    for(auto next: G[current]) {
        if(!visited[next]) {
            parent[next] = current;
            dfs(next, current, n, G);
            lowest[current] = min(lowest[current], lowest[next]);
        }
        else if(next != prev) {
            lowest[current] = min(lowest[current], prenum[next]);
        }
    }
}

set<int> articulationPoint(int n, vector<vector<int>> &G) {
    parent[0] = NIL;
    for(int i=0; i<n; i++) visited[i] = false;

    timer = 0;
    dfs(0, NIL, n, G);

    set<int> st;
    int np = 0;
    for(int i=1; i<n; i++) {
        int p = parent[i];
        if(p == 0) np++;
        else if(prenum[p] <= lowest[i]) st.insert(p);
    }
    if(np > 1) st.insert(0);
    return st;
}

int main() {
    int n, m, s, t;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i=0; i<m; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    set<int> st = articulationPoint(n, G);

    for(auto a : st) cout << a << endl;

    return 0;
}
