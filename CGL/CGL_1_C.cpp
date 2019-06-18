//Counter-Clockwise
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

Point reflect(Segment s, Point p) {
    return p + (project(s, p) - p) * 2;
}

enum {
    COUNTER_CLOCKWISE,
    CLOCKWISE,
    ONLINE_BACK,
    ONLINE_FRONT,
    ON_SEGMENT
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

int main() {
    int q;
    double x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> q;
    Point p0 = Point(x0, y0), p1 = Point(x1, y1);
    for(int i = 0; i < q; i++) {
        cin >> x2 >> y2;
        Point p2 = Point(x2, y2);
        switch(ccw(p0, p1, p2)) {
            case COUNTER_CLOCKWISE:
                cout << "COUNTER_CLOCKWISE" << endl;
                break;
            case CLOCKWISE:
                cout << "CLOCKWISE" << endl;
                break;
            case ONLINE_BACK:
                cout << "ONLINE_BACK" << endl;
                break;
            case ONLINE_FRONT:
                cout << "ONLINE_FRONT" << endl;
                break;
            case ON_SEGMENT:
                cout << "ON_SEGMENT" << endl;
                break;
            default:
                break;
        }
    }
}