#define _USE_MATH_DEFINES

#ifdef LOCAL
#include "prettyprint.hpp"
#endif

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

template <typename... Ts>
void eprint(Ts&&... ts) {
#ifdef LOCAL
    ((cerr << ts << " "), ...) << endl;
#endif
}

#define DEBUG(x...) eprint("[" #x "]:", x)

struct Point {
    ld x, y;
};

istream& operator>>(istream& in, Point& p) {
    return in >> p.x >> p.y;
}

ostream& operator<<(ostream& out, const Point& p) {
    return out << "(" << p.x << ", " << p.y << ")";
}

ld square(ld x) {
    return x * x;
}

ld dist(const Point& a, const Point& b) {
    return sqrt(square(a.x - b.x) + square(a.y - b.y));
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    assert(argc >= 2); // an input file please!
    ifstream fin(argv[1]);
    int n;
    fin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        fin >> points[i];
    }
    vector<ld> d(n, INFINITY);
    vector<bool> mark(n);
    d[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        pair<ld, int> bestPoint{INFINITY, 0};
        for (int j = 0; j < n; ++j)
            if (!mark[j])
                bestPoint = min(bestPoint, make_pair(d[j], j));
        int u = bestPoint.second;
        mark[u] = true;
        for (int j = 0; j < n; ++j)
            if (!mark[j] && dist(points[u], points[j]) < d[j])
                d[j] = dist(points[u], points[j]);
    }
    cout << "lowerbound: " << accumulate(d.begin(), d.end(), 0.l) << '\n';
}
