#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
int u, v, x;
int ans[100001];
bool vis[100001];
vector<int> g[100001];

int dfs(int cur) {
    vis[cur] = true;
    for (int nxt : g[cur]) {
        if (!vis[nxt]) ans[cur] += dfs(nxt);
    }
    return ans[cur];
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) ans[i] = 1;

    dfs(r);

    while (q--) {
        cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}
