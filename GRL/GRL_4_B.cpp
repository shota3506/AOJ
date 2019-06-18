//Topological Sort
#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

static const int MAX = 100000;

vector<int> G[MAX];
queue<int> Q;
list<int> out;
bool V[MAX] = {};
int indeg[MAX] = {};
int N;

void bfs(int u) {
    while(!Q.empty()) Q.pop();
    int v;
    Q.push(u);
    V[u] = true;
    while(!Q.empty()) {
        v = Q.front();
        Q.pop();
        out.push_back(v);
        for(auto i : G[v]) {
            indeg[i]--;
            if(indeg[i] == 0) {
                Q.push(i);
                V[i] = true;
            }
        }
    }
}

void topologivalSort() {
    for(int i = 0; i < N; i++) {
        if(indeg[i] == 0 && !V[i]) bfs(i);
    }
}

int main() {
    int M, s, t;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        indeg[t]++;
    }

    topologivalSort();

    for(auto itr = out.begin(); itr != out.end(); itr++) cout << *itr << endl;
}