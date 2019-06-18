//Fish
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Point {
    int x, y, d;
    Point() {}
    Point(int x, int y, int d): x(x), y(y), d(d) {}
};

struct Rectangle {
    Point p1, p2;
    Rectangle() {}
    Rectangle(Point p1, Point p2): p1(p1), p2(p2) {}
};

int main() {
    int N, K;
    vector<ll> X, Y, D;
    cin >> N >> K;
    Rectangle R[N];
    int x1, y1, d1, x2, y2, d2;
    for(int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
        R[i] = Rectangle(Point(x1, y1, d1), Point(x2, y2, d2));
        X.push_back(x1); X.push_back(x2);
        Y.push_back(y1); Y.push_back(y2);
        D.push_back(d1); D.push_back(d2);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(D.begin(), D.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    D.erase(unique(D.begin(), D.end()), D.end());
    int G[X.size() - 1][Y.size() - 1][D.size() - 1];
    if(X.size() == 1 || Y.size() == 1 || D.size() == 1) {
        cout << 0 << endl;
    } else {
        for(int i = 0; i < X.size() - 1; i++) {
            for(int j = 0; j < Y.size() - 1; j++) {
                for(int k = 0; k < D.size() - 1; k++) {
                    G[i][j][k] = 0;
                }
            }
        }
        for(int n = 0; n < N; n++) {
            for(int i = int(distance(X.begin(), lower_bound(X.begin(), X.end(), R[n].p1.x))); i < int(distance(X.begin(), upper_bound(X.begin(), X.end(), R[n].p2.x))) - 1; i++) {
                for(int j = int(distance(Y.begin(), lower_bound(Y.begin(), Y.end(), R[n].p1.y))); j < int(distance(Y.begin(), upper_bound(Y.begin(), Y.end(), R[n].p2.y))) - 1; j++) {
                    for(int k = int(distance(D.begin(), lower_bound(D.begin(), D.end(), R[n].p1.d))); k < int(distance(D.begin(), upper_bound(D.begin(), D.end(), R[n].p2.d))) - 1; k++) {
                        G[i][j][k]++;
                    }
                }
            }
        }
        ll v = 0;
        for(int i = 0; i < X.size() - 1; i++) {
            for(int j = 0; j < Y.size() - 1; j++) {
                for(int k = 0; k < D.size() - 1; k++) {
                    if(G[i][j][k] >= K) {
                        v += (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]) * (D[k + 1] - D[k]);
                    }
                }
            }
        }
        cout << v << endl;
    }

    return 0;
}