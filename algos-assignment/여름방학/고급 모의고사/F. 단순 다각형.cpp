#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<ll, ll> pll;

struct Point {
    ll x, y;
    int idx;
};

Point P0;

ll ccw(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

ll dist2(Point A, Point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

bool cmp(const Point &a, const Point &b) {
    ll c = ccw(P0, a, b);
    if (c == 0) return dist2(P0, a) < dist2(P0, b);
    return c > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Point> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y;
            v[i].idx = i;
        }

        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (v[i].y < v[idx].y ||
                (v[i].y == v[idx].y && v[i].x < v[idx].x)) {
                idx = i;
            }
        }
        swap(v[0], v[idx]);
        P0 = v[0];

        sort(v.begin() + 1, v.end(), cmp);
        int pt = n - 1;
        while (pt > 0 && ccw(v[0], v[n - 1], v[pt - 1]) == 0) {
            pt--;
        }
        reverse(v.begin() + pt, v.end());

        for (int i = 0; i < n; i++) {
            cout << v[i].idx << " ";
        }
        cout << "\n";
    }
}
