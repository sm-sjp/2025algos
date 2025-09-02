#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
int arr[16];
ll dp[16][(1 << 16)];

ll dfs(int cur, int visit) {
    if (visit == (1 << N) - 1) {
        return 1;
    }
    if (dp[cur][visit] != -1) return dp[cur][visit];
    dp[cur][visit] = 0;
    for (int i = 0; i < N; i++) {
        if (!(visit & (1 << i)) && abs(arr[cur] - arr[i]) > K) {
            dp[cur][visit] += dfs(i, visit | (1 << i));
        }
    }
    return dp[cur][visit];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) cin >> arr[i];
    ll res = 0;
    for (int i = 0; i < N; i++) {
        res += dfs(i, 1 << i);
    }
    cout << res;

    return 0;
}
