//PointCard
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, M, a, b;
    priority_queue<int> PQ;
    cin >> N >> M;

    int cnt = 0, cost = 0;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        if(a >= N) cnt++;
        else PQ.push(a);
    }

    while(cnt < M - 1) {
        cost += N - PQ.top();
        PQ.pop();
        cnt++;
    }

    cout << cost << endl;
}