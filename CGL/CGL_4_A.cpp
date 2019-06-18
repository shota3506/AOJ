//Convex Hull
#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

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

typedef vector<Point> Polygon;

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

int contains(Polygon g, Point p) {
    int n = int(g.size());
    bool x = false;
    for(int i = 0; i < n; i++) {
        Vector a = g[i] - p;
        Vector b = g[(i + 1) % n] - p;
        if(fabs(cross(a, b)) < ESP && dot(a, b) < ESP) return 1;
        if(a.y > b.y) swap(a, b);
        if(cross(a, b) > ESP && a.y < ESP && b.y > ESP) x = !x;
    }
    return (x ? 2 : 0);
}

Polygon getConvexHull(vector<Point> s) {
    if(s.size() < 3) return s;
    Polygon u, l;
    sort(s.begin(), s.end());

    u.emplace_back(s[0]);
    u.emplace_back(s[1]);
    l.emplace_back(s[s.size() - 1]);
    l.emplace_back(s[s.size() - 2]);

    for(int i = 2; i < s.size(); i++) {
        for(int n = int(u.size()); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
            u.pop_back();
        }
        u.emplace_back(s[i]);
    }

    for(int i = int(s.size()) - 3; i >= 0; i--) {
        for(int n = int(l.size()); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
            l.pop_back();
        }
        l.emplace_back(s[i]);
    }

    reverse(l.begin(), l.end());
    for(int i = int(u.size()) - 2; i > 0; i--) l.emplace_back(u[i]);
    return l;
}

int main() {
    int n;
    double x, y;
    vector<Point> s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        s.emplace_back(Point(x, y));
    }
    Polygon g = getConvexHull(s);
    int m = int(g.size());
    cout << m << endl;
    int l = 0;
    for(int i = 1; i < m; i++) {
        if(g[i].y < g[l].y) l = i;
        else if(fabs(g[i].y - g[l].y) < ESP && g[i].x < g[l].x) l = i;
    }
    for(int i = 0; i < m; i++) {
        cout << g[(i + l) % m].x << " " << g[(i + l) % m].y << endl;
    }
}