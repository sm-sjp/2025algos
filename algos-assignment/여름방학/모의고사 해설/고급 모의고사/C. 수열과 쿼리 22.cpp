#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>
#define ll long long

struct T {
    int k, qs, qe, idx;
};
const int N = 1e5 + 5;
ll tree[4 * N];
ll ret[N];
ll arr[N];

void update(int node, int s, int e, int idx, ll diff) {
    if (idx < s || e < idx) return;
    tree[node] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, diff);
    update(node * 2 + 1, mid + 1, e, idx, diff);
}

ll query(int node, int s, int e, int qs, int qe) {
    if (e < qs || qe < s) return 0;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, qs, qe) +
           query(node * 2 + 1, mid + 1, e, qs, qe);
}

bool cmp(T a, T b) { return a.k < b.k; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        arr[i] = d;
        update(1, 1, n, i, d);
    }

    vector<pii> a;
    vector<T> b;
    int t = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int x, y;
            cin >> x >> y;
            a.push_back({x, y});
        } else {
            int k, x, y;
            cin >> k >> x >> y;
            b.push_back({k, x, y, t++});
        }
    }
    sort(b.begin(), b.end(), cmp);

    int applied = 0;
    for (auto &qu : b) {
        while (applied < qu.k) {
            auto [idx, newVal] = a[applied];
            ll diff = newVal - arr[idx];
            arr[idx] = newVal;
            update(1, 1, n, idx, diff);
            applied++;
        }
        ret[qu.idx] = query(1, 1, n, qu.qs, qu.qe);
    }

    for (int i = 0; i < t; i++) cout << ret[i] << "\n";

    return 0;
}
