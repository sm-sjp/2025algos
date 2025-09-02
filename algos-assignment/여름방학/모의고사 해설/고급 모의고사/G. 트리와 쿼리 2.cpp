#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
int len;
vector<pair<int, ll>> graph[100001];
int parent[100001][17];
int depth[100001];
ll cost[100001][17];

pair<int, ll> LCA(int u, int v) {
    ll ret = 0;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    for (int k = 0; diff; ++k) {
        if (diff & 1) {
            ret += cost[u][k];
            u = parent[u][k];
        }
        diff >>= 1;
    }

    if (u != v) {
        for (int k = len - 1; k >= 0; --k) {
            if (parent[u][k] != parent[v][k]) {
                ret += cost[u][k] + cost[v][k];
                u = parent[u][k];
                v = parent[v][k];
            }
        }
        ret += cost[u][0] + cost[v][0];
        u = parent[u][0];
    }
    return {u, ret};
}

void dfs(int cur, int before) {
    for (auto &next : graph[cur]) {
        if (next.first == before) continue;
        parent[next.first][0] = cur;
        cost[next.first][0] = next.second;
        depth[next.first] = depth[cur] + 1;
        dfs(next.first, cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    ll u, v, w;
    len = (int)log2(N) + 1;

    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs(1, 0);

    for (int k = 0; k + 1 < len; ++k) {
        for (int i = 1; i <= N; ++i) {
            parent[i][k + 1] = parent[parent[i][k]][k];
            cost[i][k + 1] = cost[i][k] + cost[parent[i][k]][k];
        }
    }

    cin >> M;
    while (M--) {
        int q;
        cin >> q;
        if (q == 1) {
            cin >> u >> v;
            cout << LCA(u, v).second << "\n";
        } else {
            ll t;
            cin >> u >> v >> t;
            auto lca = LCA(u, v);
            int d1 = depth[u] - depth[lca.first];
            int d2 = depth[v] - depth[lca.first];

            int cur;
            if (t - 1 <= d1) {
                cur = u;
                int diff = t - 1;
                for (int i = 0; diff; ++i) {
                    if (diff & 1) cur = parent[cur][i];
                    diff >>= 1;
                }
            } else {
                cur = v;
                int diff = d1 + d2 - (t - 1);
                for (int i = 0; diff; ++i) {
                    if (diff & 1) cur = parent[cur][i];
                    diff >>= 1;
                }
            }
            cout << cur << "\n";
        }
    }

    return 0;
}
