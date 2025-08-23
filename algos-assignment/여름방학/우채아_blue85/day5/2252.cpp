#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> indeg;
vector<vector<int>> g;

void input() {
    cin >> n >> m;
    indeg.assign(n + 1, 0);
    g.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
}

void topo_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    for (int i = 0; i < n; i++) {
        if (q.empty()) return;
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int nxt : g[cur]) {
            if (--indeg[nxt] == 0) q.push(nxt);
        }
    }
}

int main() {

    input();
    topo_sort();
    return 0;
}
