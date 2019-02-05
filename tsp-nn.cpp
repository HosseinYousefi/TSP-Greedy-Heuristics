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
    srand((unsigned)time(0));
    assert(argc >= 2); // an input file please!
    ifstream fin(argv[1]);
    int n;
    fin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        fin >> points[i];
    }
    vector<bool> mark(n);
    int visitedCount = 0, current = rand() % n;
    ld totalCost = 0;
    while (visitedCount < n - 1) {
        mark[current] = true;
        ++visitedCount;
        pair<ld, int> best{1e20, 0};
        for (int i = 0; i < n; ++i) {
            if (!mark[i])
                best = min(best, make_pair(dist(points[i], points[current]), i));
        }
        totalCost += best.first;
        current = best.second;
    }
    totalCost += dist(points[current], points[0]);
    cout << totalCost << '\n';
}
