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

map<int, int> id;
vector<Point> points;
vector<bool> mark;
vector<vector<int>> adj;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned)time(0));
    int n;
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x >> points[i];
        id[i] = x;
    }
    mark.resize(n);
    int current = rand() % n;
    ld totalCost = 0;
    int finish = current;
    cout << id[current] << ' ';
    for (int cnt = 0; cnt < n - 1; ++cnt) {
        mark[current] = true;
        pair<ld, int> best{INFINITY, 0};
        for (int i = 0; i < n; ++i) {
            if (!mark[i])
                best = min(best, make_pair(dist(points[i], points[current]), i));
        }
        totalCost += best.first;
        current = best.second;
        cout << id[current] << ' ';
    }
    cout << id[finish] << ' ';
    totalCost += dist(points[current], points[0]);
}
