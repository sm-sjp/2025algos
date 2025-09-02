#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<ll, ll> pll;

ll ccw(pll A, pll B, pll C) {
    return A.X * B.Y + B.X * C.Y + C.X * A.Y - A.Y * B.X - B.Y * C.X -
           C.Y * A.X;
}

void convexHull(vector<pll>& v) {
    sort(v.begin(), v.end());
    vector<pll> L, R;
    for (pll i : v) {
        while (L.size() >= 2 && ccw(L[L.size() - 2], L[L.size() - 1], i) <= 0) {
            L.pop_back();
        }
        L.emplace_back(i);
        while (R.size() >= 2 && ccw(R[R.size() - 2], R[R.size() - 1], i) >= 0) {
            R.pop_back();
        }
        R.emplace_back(i);
    }
    v.clear();
    for (int i = 0; i < L.size() - 1; i++) v.emplace_back(L[i]);
    for (int i = R.size() - 1; i > 0; i--) {
        v.emplace_back(R[i]);
    }
}
ll dist2(pll a, pll b) {
    ll dx = a.X - b.X;
    ll dy = a.Y - b.Y;
    return dx * dx + dy * dy;
}
ll rotatingCalipers(const vector<pll>& hull) {
    int m = hull.size();
    if (m == 1) return 0;
    if (m == 2) return dist2(hull[0], hull[1]);

    ll ans = 0;
    int j = 1;
    for (int i = 0; i < m; i++) {
        int ni = (i + 1) % m;
        while (true) {
            int nj = (j + 1) % m;
            ll cross1 = abs(ccw(hull[i], hull[ni], hull[j]));
            ll cross2 = abs(ccw(hull[i], hull[ni], hull[nj]));
            if (cross2 > cross1)
                j = nj;
            else
                break;
        }
        ans = max(ans, dist2(hull[i], hull[j]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;
    cout.precision(6);

    int n;
    cin >> n;
    vector<pll> inp;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        inp.emplace_back(x, y);
    }
    convexHull(inp);

    ll res = rotatingCalipers(inp);
    cout << sqrt((long double)res) << "\n";
    return 0;
}
