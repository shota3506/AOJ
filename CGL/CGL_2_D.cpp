//Distance
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

typedef Segment Line;

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

Point reflect(Segment s, Point p) {
    return p + (project(s, p) - p) * 2;
}

enum {
    COUNTER_CLOCKWISE = 1,
    CLOCKWISE = -1,
    ONLINE_BACK = 2,
    ONLINE_FRONT = -2,
    ON_SEGMENT = 0
};

int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > ESP) return COUNTER_CLOCKWISE;
    else if (cross(a, b) < -ESP) return CLOCKWISE;
    else if (dot(a, b) < -ESP) return ONLINE_BACK;
    else if (a.norm() < b.norm()) return ONLINE_FRONT;
    else return ON_SEGMENT;
}

bool intersect(Point p0, Point p1, Point p2, Point p3) {
    return (ccw(p0, p1, p2) * ccw(p0, p1, p3) <= 0 && ccw(p2, p3, p0) * ccw(p2, p3, p1) <= 0);
}

bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistancePP(Point p1, Point p2) {
    return (p2 - p1).abs();
}

double getDistanceLP(Line l, Point p) {
    return fabs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}

double getDistanceSP(Segment s, Point p) {
    if(dot(s.p2 - s.p1, p - s.p1) < 0) {
        return getDistancePP(s.p1, p);
    } else if(dot(s.p1 - s.p2, p - s.p2) < 0) {
        return getDistancePP(s.p2, p);
    } else {
        return getDistanceLP(s, p);
    }
}

double getDistance(Segment s1, Segment s2) {
    if(intersect(s1, s2)) return 0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

int main() {
    int q, x0, y0, x1, y1, x2, y2, x3, y3;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Segment s1 = Segment(Point(x0, y0), Point(x1, y1));
        Segment s2 = Segment(Point(x2, y2), Point(x3, y3));
        cout << setprecision(15) << getDistance(s1, s2) << endl;
    }
}