#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> graph[10001];
    vector<int> degree(n + 1, 0);
    vector<int> ans(n + 1);

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        degree[e]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            pq.push(i);
            ans[i] = 1;
        }
    }

    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();

        for (auto i : graph[top]) {
            int nxt = i.first;
            int time = i.second;
            degree[nxt]--;
            if (time >= 7)
                ans[nxt] = max(ans[nxt], ans[top] + time + 1);
            else
                ans[nxt] = max(ans[nxt], ans[top] + time);
            if (degree[nxt] == 0) pq.push(nxt);
        }
    }
    int mx = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (mx < ans[i]) mx = ans[i];
    }
    cout << mx;
    return 0;
}
