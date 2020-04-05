//Articulation Point
#include <iostream>
#include <vector>
#include <set>

using namespace std;

static const int MAX = 100000;
static const int NIL = -1;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int N, num = 1;
vector<int> G[MAX];
set<int> st;
int colors[MAX], prenum[MAX], parent[MAX], lowest[MAX];

void dfs(int u) {
    prenum[u] = num++;
    lowest[u] = prenum[u];

    for(auto v: G[u]) {
        if(colors[v] == WHITE) {
            colors[u] = GRAY;
            parent[v] = u;
            dfs(v);
            lowest[u] = min(lowest[u], lowest[v]);
        }
        else {
            lowest[u] = min(lowest[u], prenum[v]);
        }
    }
    colors[u] = BLACK;
}


void articulationPoint() {
    st.clear();
    for(int i=0; i<N; i++) colors[i] = WHITE;
    parent[0] = NIL;
    colors[0] = GRAY;

    dfs(0);

    int cnt = 0;
    for(int i=1; i<N; i++) {
        if(parent[i] == 0) cnt++;
        else if(prenum[parent[i]] <= lowest[i]) st.insert(parent[i]);
    }
    if(cnt > 1) st.insert(0);
};


int main() {
    int M, s, t;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    articulationPoint();

    for(auto itr = st.begin(); itr != st.end(); itr++) cout << *itr << endl;
}