//Zombie Island
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

static const int MAX = 100000;

int N, M, K, S, P, Q;

enum {
    SAFE,
    DENGEROUS,
    ZOMBIE
};

struct City {
    int state = SAFE;
    vector<int> adj;
};

City C[MAX + 1];
bool visited[MAX + 1];

void setState(int t) {
    queue<pair<int, int> > Queue;
    for(int i = 0; i < MAX + 1; i++) visited[i] = false;
    Queue.push(make_pair(t, 0));
    visited[t] = true;
    while(!Queue.empty()) {
        pair<int, int> p = Queue.front();
        Queue.pop();
        if(p.first != t && C[p.first].state == ZOMBIE) continue;
        if(C[p.first].state == SAFE) C[p.first].state = DENGEROUS;
        if(p.second == S) continue;
        for(auto i: C[p.first].adj) {
            if(!visited[i]) {
                Queue.push(make_pair(i, p.second + 1));
                visited[i] = true;
            }
        }
    }
}

ll dijkstra() {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > PQ;
    ll d[MAX + 1];
    for(int i = 0; i < MAX + 1; i++) d[i] = LONG_LONG_MAX;
    PQ.push(make_pair(0, 1));
    d[1] = 0;
    while(!PQ.empty()) {
        pair<ll, int> p = PQ.top();
        PQ.pop();
        for(auto i: C[p.second].adj) {
            if(i == N) {
                if(d[i] > p.first) d[i] = p.first;
            } else if(C[i].state == SAFE) {
                if(d[i] > p.first + P) {
                    d[i] = p.first + P;
                    PQ.push(make_pair(p.first + P, i));
                }
            } else if(C[i].state == DENGEROUS){
                if(d[i] > p.first + Q) {
                    d[i] = p.first + Q;
                    PQ.push(make_pair(p.first + Q, i));
                }
            }
        }
    }
    return d[N];
}

int main() {
    cin >> N >> M >> K >> S >> P >> Q;

    int c;
    int zombie_city[K];
    for(int i = 0; i < K; i++) {
        cin >> c;
        zombie_city[i] = c;
        C[c].state = ZOMBIE;
    }
    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        C[a].adj.push_back(b);
        C[b].adj.push_back(a);
    }

    for(int i = 0; i < K; i++) {
        setState(zombie_city[i]);
    }

    cout << dijkstra() << endl;
}