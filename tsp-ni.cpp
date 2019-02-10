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

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned)time(0));
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x >> points[i];
        id[i] = x;
    }
    int times = 20;
    vector<int> bestNext;
    ld bestCost = INFINITY;
    int firstOne, bestOne;
    while (times--) { // trying 20 random starting cities
        vector<bool> mark(n);
        int current = firstOne = rand() % n;
        ld totalCost = 0;
        vector<int> nxt(n, -1); // storing the tour in some sort of circular linked list for easier insertion
        nxt[current] = current;
        for (int cnt = 0; cnt < n - 1; ++cnt) {
            mark[current] = true;
            ld best = INFINITY;
            int neighbor = -1, insertAfter = -1;
            for (int i = 0; i < n; ++i) {
                if (!mark[i]) {
                    int cur = firstOne;
                    for (int j = 0; j <= cnt; ++j) {
                        if (
                                dist(points[i], points[cur]) 
                            +   dist(points[i], points[nxt[cur]])
                            -   dist(points[cur], points[nxt[cur]])
                            <   best
                        ) {
                            best =      
                                dist(points[i], points[cur]) 
                            +   dist(points[i], points[nxt[cur]])
                            -   dist(points[cur], points[nxt[cur]]);
                            neighbor = i;
                            insertAfter = cur;
                        }
                        cur = nxt[cur];
                    }
                }
            }
            current = neighbor;
            totalCost += best;
            nxt[current] = nxt[insertAfter];
            nxt[insertAfter] = current;
        }
        if (bestCost > totalCost) { // keeping the best one
            bestCost = totalCost;
            bestNext = nxt;
            bestOne = firstOne;
        }
    }
    int current;
    current = bestOne;
    cout << id[bestOne] << ' ';
    while (bestNext[current] != bestOne) {
        current = bestNext[current];
        cout << id[current] << ' ';
    }
    cout << id[bestOne] << '\n';
    // cout << totalCost << '\n';
}
