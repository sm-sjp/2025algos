#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n, full;
vector<vector<int>> g, dp;

void input() {
    cin >> n;
    full = (1 << n) - 1;
    dp = vector<vector<int>>(n, vector<int>(full + 1, -1));
    g = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
}

int dfs(int cur, int mask) {
    if (mask == full) {
        return g[cur][0] ? g[cur][0] : INF;
    }

    if (dp[cur][mask] != -1) {
        return dp[cur][mask];
    }
    dp[cur][mask] = INF;

    for (int nxt = 1; nxt < n; nxt++) {
        int bit = 1 << nxt;
        if ((mask & bit) || !g[cur][nxt]) continue;

        dp[cur][mask] = min(dp[cur][mask], dfs(nxt, mask | bit) + g[cur][nxt]);
    }
    return dp[cur][mask];
}

int main() {
    input();
    cout << dfs(0, 1);
    return 0;
}
