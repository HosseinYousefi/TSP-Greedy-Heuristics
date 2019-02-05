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

vector<int> par;

int find(int v) {
    return par[v] = (par[v] == v ? v : find(par[v]));
}

void unite(int u, int v) {
    par[find(u)] = find(v);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    assert(argc >= 2); // an input file please!
    ifstream fin(argv[1]);
    int n;
    fin >> n;
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        fin >> points[i];
    }
    vector<tuple<ld, int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.emplace_back(dist(points[i], points[j]), i, j);
        }
    }
    sort(edges.begin(), edges.end());
    vector<int> deg(n);
    int no = 0;
    ld answer = 0;
    for (auto [d, u, v] : edges) {
        if (no == n - 1) {
            if (deg[v] < 2 && deg[u] < 2) {
                answer += d;
                ++deg[v];
                ++deg[u];
                unite(u, v);
                ++no;
                break;
            }
        } else {
            if (find(u) != find(v) && deg[v] < 2 && deg[u] < 2) {
                answer += d;
                ++deg[v];
                ++deg[u];
                unite(u, v);
                ++no;
            }
        }
    }
    cout << answer << '\n';
}
