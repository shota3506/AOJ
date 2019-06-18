//Snake JOI
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

static const int MAX = 10000;

enum TYPE {
    COLD = 0,
    CONFORTABLE = 1,
    HOT = 2
};

struct Corridor {
    int target, cost;
    Corridor(int target, int cost): target(target), cost(cost) {}
};

struct Room {
public:
    int id, type;
    vector<Corridor> edge;
    Room() {}
    Room(int id, int type): id(id), type(type) {}
};

struct State {
    int id, time, prev_type, d;
    State(int id, int time, int prev_type, int d): id(id), time(time), prev_type(prev_type), d(d) {}
    bool operator < (const State &s) const {
        return time > s.time;
    };
};

int N, M, X;
Room rooms[MAX];
int min_time[MAX][2][201];

int dijkstra() {
    priority_queue<State> PQ;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 201; k++) min_time[i][j][k] = INT_MAX;
        }
    }
    min_time[0][0][0] = 0;
    PQ.push(State(0, 0, COLD, 0));
    int ans = INT_MAX, next_time, next_type, next_d;
    while(!PQ.empty()) {
        if(PQ.top().id == N - 1) {
            ans = min(ans, PQ.top().time);
            PQ.pop();
            continue;
        }
        if(PQ.top().time > ans) break;
        for(auto c: rooms[PQ.top().id].edge) {
            next_d = min(X, PQ.top().d + c.cost);
            next_time = PQ.top().time + c.cost;
            if(abs(PQ.top().prev_type - rooms[c.target].type) > 1 && next_d < X) continue;
            if(rooms[c.target].type == CONFORTABLE) {
                next_type = PQ.top().prev_type;
                if(min_time[c.target][next_type / 2][next_d] <= next_time) continue;
                min_time[c.target][next_type / 2][next_d] = next_time;
                PQ.push(State(c.target, next_time, next_type, next_d));
            } else {
                next_type = rooms[c.target].type;
                if(min_time[c.target][next_type / 2][0] <= next_time) continue;
                min_time[c.target][next_type / 2][0] = next_time;
                PQ.push(State(c.target, next_time, next_type, 0));
            }
        }
        PQ.pop();
    }
    return ans;
}

int main() {
    int t, a, b, d;
    scanf("%d %d %d", &N, &M, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        rooms[i] = Room(i, t);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &d);
        a--;
        b--;
        rooms[a].edge.emplace_back(Corridor(b, d));
        rooms[b].edge.emplace_back(Corridor(a, d));
    }

    cout << dijkstra() << endl;
}