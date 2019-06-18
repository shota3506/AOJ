//Parallel/Orthogonal
#include <iostream>
#include <math.h>

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

int main() {
    int q, x0, y0, x1, y1, x2, y2, x3, y3;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point s0 = Point(x0, y0);
        Point s1 = Point(x1, y1);
        Point s2 = Point(x2, y2);
        Point s3 = Point(x3, y3);

        Vector v1 = s1 - s0;
        Vector v2 = s3 - s2;

        if(isParallel(v1, v2)) cout << 2 << endl;
        else if(isOrthogonal(v1, v2)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}