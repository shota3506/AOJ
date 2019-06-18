//Cross Point of Circles
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

class Circle {
public:
    Point c;
    double r;
    explicit Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

double arg(Vector p) {
    return atan2(p.y, p.x);
}

Vector polar(double r, double theta) {
    return Point(cos(theta) * r, sin(theta) * r);
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

Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s1.p2 - s1.p1;
    double d1 = fabs(cross(base, s2.p1 - s1.p1));
    double d2 = fabs(cross(base, s2.p2 - s1.p1));
    return s2.p1 + (s2.p2 - s2.p1) * (d1 / (d1 + d2));
}

pair<Point, Point> getCrossPoint(Circle c, Line l) {
    Vector base = l.p2 - l.p1;
    double d = getDistanceLP(l, c.c);
    Point m = project(l, c.c);
    double t = sqrt(pow(c.r, 2.0) - pow(d, 2.0)) / base.abs();
    return make_pair(m + base * t, m - base * t);
}

pair<Point, Point> getCrossPoint(Circle c1, Circle c2) {
    double d = (c1.c - c2.c).abs();
    double a = acos((pow(d, 2.0) + pow(c1.r, 2.0) - pow(c2.r, 2.0)) / (2 * d * c1.r));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

int main() {
    int q;
    double c1x, c1y, r1, c2x, c2y, r2;
    cin >> c1x >> c1y >> r1 >> c2x >> c2y >> r2;
    Circle c1 = Circle(Point(c1x, c1y), r1);
    Circle c2 = Circle(Point(c2x, c2y), r2);
    pair<Point, Point> p = getCrossPoint(c1, c2);
    if(p.first.x > p.second.x) swap(p.first, p.second);
    else if (fabs(p.first.x - p.second.x) < ESP && p.first.y > p.second.y) swap(p.first, p.second);
    printf("%.8f %.8f %.8f %.8f\n", p.first.x, p.first.y, p.second.x, p.second.y);
}