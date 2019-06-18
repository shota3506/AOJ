//Koch Curve
#include <iostream>
#include <math.h>

using namespace std;

struct Point {
    double x = 0, y = 0;
};

void koch(int d, Point p1, Point p2) {
    if(d == 0) return;
    Point s, t, u;
    double th = M_PI * 60.0 / 180.0;
    s.x = (2 * p1.x + p2.x) / 3.0;
    s.y = (2 * p1.y + p2.y) / 3.0;
    t.x = (p1.x + 2 * p2.x) / 3.0;
    t.y = (p1.y + 2 * p2.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    koch(d-1, p1, s);
    cout << s.x << " " << s.y << endl;
    koch(d-1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(d-1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(d-1, t, p2);
}

int main() {
    int n;
    cin >> n;

    Point p1, p2;
    p2.x = 100.0;

    std::cout << std::fixed;
    cout << p1.x << " " << p1.y << endl;
    koch(n, p1, p2);
    cout << p2.x << " " << p2.y << endl;
}