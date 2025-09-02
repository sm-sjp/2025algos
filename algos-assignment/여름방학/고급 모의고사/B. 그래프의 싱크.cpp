#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define pii pair<int, int>

int V, E, dtime = 1;
vector<int> graph[5001];
vector<int> rev_graph[5001];
vector<int> SCC[5001];
vector<int> rev_search;
int SCC_id[5001];
bool visited[10001], rev_visited[10001];

void dfs(int cur) {
    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++) {
        int nxt = graph[cur][i];
        if (visited[nxt]) continue;
        dfs(nxt);
    }
    rev_search.push_back(cur);
}

void rev_dfs(int cur, int id) {
    rev_visited[cur] = true;
    SCC[id].push_back(cur);
    SCC_id[cur] = id;
    for (int i = 0; i < rev_graph[cur].size(); i++) {
        int nxt = rev_graph[cur][i];
        if (rev_visited[nxt]) {
            if (SCC_id[nxt] != id) SCC[SCC_id[nxt]].clear();
            continue;
        }
        rev_dfs(nxt, id);
    }
}

void solve() {
    for (int i = 1; i <= V; i++) {
        if (visited[i]) continue;
        dfs(i);
    }
    int scc_id = 0;
    for (int i = rev_search.size() - 1; i >= 0; i--) {
        int now = rev_search[i];
        if (rev_visited[now]) continue;
        rev_dfs(now, scc_id);
        scc_id++;
    }
    vector<int> res;
    for (int i = 0; i < V; i++) {
        for (auto &w : SCC[i]) {
            res.push_back(w);
        }
    }
    sort(res.begin(), res.end());
    for (auto &w : res) {
        cout << w << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while (true) {
        cin >> V;
        if (!V) break;
        cin >> E;
        for (int i = 0; i < E; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            rev_graph[b].push_back(a);
        }
        solve();
        for (int i = 0; i < 5001; i++) {
            graph[i].clear();
            rev_graph[i].clear();
            SCC[i].clear();
        }
        rev_search.clear();
        memset(SCC_id, 0, sizeof(SCC_id));
        memset(visited, 0, sizeof(visited));
        memset(rev_visited, 0, sizeof(rev_visited));
    }

    return 0;
}
