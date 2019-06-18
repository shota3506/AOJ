//Projection
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

static const double ESP = 1e-10;

bool equals(double a, double b) { return fabs(a - b) < ESP; }

class Point {
public:
    double x, y;

    explicit Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator - (const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator * (double a) { return Point(a * x, a * y); }
    Point operator / (double a) { return Point(a / x, a / y); }

    double norm() { return x * x + y * y; }
    double abs() { return sqrt(norm()); }

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x - p.x) < ESP && fabs(y - p.y) < ESP;
    }
};

typedef Point Vector;

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2): p1(p1), p2(p2) {}
};

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

bool isParallel(Vector v1, Vector v2) {
    return equals(cross(v1, v2), 0.0);
}

bool isOrthogonal(Vector v1, Vector v2) {
    return equals(dot(v1, v2), 0.0);
}

Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    return s.p1 + (base * (dot(base, p - s.p1) / base.norm()));
}

int main() {
    int q;
    double x, y, x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2 >> q;
    Point p1 = Point(x1, y1), p2 = Point(x2, y2);
    Segment s = Segment(p1, p2);
    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        Point p = Point(x, y);
        Point x = project(s, p);
        cout << setprecision(15) << x.x << " " << x.y << endl;
    }
}