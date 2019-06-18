//Food Stalls
#include <iostream>
#include <climits>
#include <vector>

using namespace std;
static const int MAX = 1000;

int H, W;
int A[MAX + 2][MAX + 2], min_cost[MAX + 1][MAX + 1][16];
//(i - 1, j + 1), (i, j + 1), (i + 1. j), (i + 1, j - 1)

enum {
    SOUTHWEST = 0,
    SOUTH = 1,
    EAST = 2,
    NORTHEAST = 3,
    NORTH = 4,
    WEST = 5
};

int main() {
    cin >> H >> W;

    for(int i = 0; i < H + 2; i++) {
        A[i][0] = 0;
        A[i][W + 1] = 0;
    }
    for(int j = 0; j < W + 2; j++) {
        A[0][j] = 0;
        A[H + 1][j] = 0;
    }

    char c;
    for(int i = 1; i < H + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            cin >> c;
            if(c == '.') A[i][j] = 0;
            else A[i][j] = c - '0';
        }
    }

    for(int i = 1; i < H + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            for(int k = 0; k < 16; k++) min_cost[i][j][k] = INT_MAX;
        }
    }
    min_cost[1][1][0] = 0;

    for(int i = 1; i < H + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            for(int k = 0; k < 16; k++) {
                if(min_cost[i][j][k] == INT_MAX) continue;
                int next_cost, next_state;
                vector<int> v;
                //go EAST
                if(j != W) {
                    next_state = ((k & 1 << SOUTH) ? (1 << SOUTHWEST) : 0);
                    next_cost = (k & 1 << EAST) ? min_cost[i][j][k] : min_cost[i][j][k] + A[i][j + 1];
                    if(A[i - 1][j + 1] != 0 && !(k & 1 << NORTHEAST)) {
                        next_cost += A[i - 1][j + 1];
                        v.push_back(NORTH);
                    }
                    if(A[i][j + 2] != 0) {
                        next_cost += A[i][j + 2];
                        v.push_back(EAST);
                        next_state += (1 << EAST);
                    }
                    if(A[i + 1][j + 1] != 0) {
                        next_cost += A[i + 1][j + 1];
                        v.push_back(SOUTH);
                        next_state += (1 << SOUTH);
                    }
                    if(v.size() > 1) {
                        for(auto l: v) {
                            if(l == NORTH) min_cost[i][j + 1][next_state] = min(min_cost[i][j + 1][next_state], next_cost - A[i - 1][j + 1]);
                            else if(l == EAST) min_cost[i][j + 1][next_state - (1 << EAST)] = min(min_cost[i][j + 1][next_state - (1 << EAST)], next_cost - A[i][j + 2]);
                            else min_cost[i][j + 1][next_state - (1 << SOUTH)] = min(min_cost[i][j + 1][next_state - (1 << SOUTH)], next_cost - A[i + 1][j + 1]);
                        }
                    } else {
                        min_cost[i][j + 1][((k & 1 << SOUTH) ? (1 << SOUTHWEST) : 0)] =
                                min(min_cost[i][j + 1][((k & 1 << SOUTH) ? (1 << SOUTHWEST) : 0)],
                                    ((k & 1 << EAST) ? min_cost[i][j][k] : min_cost[i][j][k] + A[i][j + 1]));
                    }
                }
                //go SOUTH
                if(i != H) {
                    v.clear();
                    next_state = ((k & 1 << EAST) ? (1 << NORTHEAST) : 0);
                    next_cost = (k & 1 << SOUTH) ? min_cost[i][j][k] : min_cost[i][j][k] + A[i + 1][j];
                    if(A[i + 1][j - 1] != 0 && !(k & 1 << SOUTHWEST)) {
                        next_cost += A[i + 1][j - 1];
                        v.push_back(WEST);
                    }
                    if(A[i + 2][j] != 0) {
                        next_cost += A[i + 2][j];
                        v.push_back(SOUTH);
                        next_state += (1 << SOUTH);
                    }
                    if(A[i + 1][j + 1] != 0) {
                        next_cost += A[i + 1][j + 1];
                        v.push_back(EAST);
                        next_state += (1 << EAST);
                    }
                    if(v.size() > 1) {
                        for(auto l: v) {
                            if(l == WEST) min_cost[i + 1][j][next_state] = min(min_cost[i + 1][j][next_state], next_cost - A[i + 1][j - 1]);
                            else if(l == SOUTH) min_cost[i + 1][j][next_state - (1 << SOUTH)] = min(min_cost[i + 1][j][next_state - (1 << SOUTH)], next_cost - A[i + 2][j]);
                            else min_cost[i + 1][j][next_state - (1 << EAST)] = min(min_cost[i + 1][j][next_state - (1 << EAST)], next_cost - A[i + 1][j + 1]);
                        }
                    } else {
                        min_cost[i + 1][j][((k & 1 << EAST) ? (1 << NORTHEAST) : 0)] =
                                min(min_cost[i + 1][j][((k & 1 << EAST) ? (1 << NORTHEAST) : 0)],
                                    (k & 1 << SOUTH) ? min_cost[i][j][k] : min_cost[i][j][k] + A[i + 1][j]);
                    }
                }
            }
        }
    }

    cout << min_cost[H][W][0] << endl;

    return 0;
}