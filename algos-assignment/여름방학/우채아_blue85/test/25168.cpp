#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1, 0);
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        degree[e]++;
        adj[s].emplace_back(e, w);
    }

    deque<int> q;
    vector<int> res(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push_back(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop_front();

        for (auto &p : adj[x]) {
            int e = p.first;
            int w = p.second;

            degree[e]--;
            if (w >= 7) {
                res[e] = max(res[e], res[x] + w + 1);
            } else {
                res[e] = max(res[e], res[x] + w);
            }

            if (degree[e] == 0) {
                q.push_back(e);
            }
        }
    }

    cout << *max_element(res.begin(), res.end()) << "\n";

    return 0;
}
