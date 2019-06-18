//Taxis
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
static const int MAX = 5000;

int N, K;
int C[MAX + 1], R[MAX + 1], min_cost[MAX + 1];
vector<int> G[MAX + 1], H[MAX + 1];

void solve() {
    priority_queue<pair<int, int> > PQ;
    min_cost[1] = 0;
    PQ.push(make_pair(0, 1));
    while(!PQ.empty()) {
        pair<int, int> p = PQ.top();
        PQ.pop();
        if(p.first > min_cost[p.second]) continue;
        int cost = p.first + C[p.second];
        for(auto u: H[p.second]) {
            if(min_cost[u] > cost) {
                min_cost[u] = cost;
                PQ.push(make_pair(cost, u));
            }
        }
    }
}

void bfs(int u) {
    bool visited[N + 1];
    queue<pair<int, int> > Q;
    for(int i = 0; i < N + 1; i++) visited[i] = false;
    Q.push(make_pair(u, 0));
    visited[u] = true;
    int r = R[u];
    while(!Q.empty()) {
        pair<int, int> q = Q.front();
        Q.pop();
        for(auto j: G[q.first]) {
            if(!visited[j]) {
                visited[j] = true;
                if(q.second < r) {
                    H[u].push_back(j);
                    Q.push(make_pair(j, q.second + 1));
                }
            }
        }
    }
}

int main() {
    cin >> N >> K;
    for(int i = 1; i < N + 1; i++) cin >> C[i] >> R[i];
    int a, b;
    for(int j = 0; j < K; j++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < MAX + 1; i++) min_cost[i] = INT_MAX;

    for(int i = 1; i < N; i++) bfs(i);
    solve();

    cout << min_cost[N] << endl;
}