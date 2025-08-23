#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tuple<int,int,int>> v(n);

    for (int i = 0; i < n; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        v[i] = {s, e, c};
    }

    sort(v.begin(), v.end());

    vector<tuple<int,int,int>> res;
    int st, ed, cost;
    tie(st, ed, cost) = v[0];

    for (int i = 1; i < n; i++) {
        int ns, ne, nc;
        tie(ns, ne, nc) = v[i];

        if (ed >= ns) {
            ed = max(ed, ne);
            cost = min(cost, nc);
        } else {
            res.push_back({st, ed, cost});
            st = ns;
            ed = ne;
            cost = nc;
        }
        if (i == n - 1) {
            res.push_back({st, ed, cost});
        }
    }
    if (n == 1) {
        res.push_back({st, ed, cost});
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto &[s, e, c] : res) {
        cout << s << " " << e << " " << c << '\n';
    }
    return 0;
}
