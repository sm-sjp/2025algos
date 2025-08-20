#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
bool found = false;

void dfs(int node, int depth) {
    if (depth == 5 || found) { // depth=5 → A-B-C-D-E 완성
        found = true;
        return;
    }

    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, depth + 1);
        }
    }
    visited[node] = false; // backtracking
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.assign(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        dfs(i, 1);
        if (found) break;
    }

    cout << (found ? 1 : 0) << "\n";
    return 0;
}
