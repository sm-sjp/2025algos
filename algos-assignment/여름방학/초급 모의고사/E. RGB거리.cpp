#include <algorithm>
#include <iostream>
using namespace std;

int dp[1001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    int red, green, blue;
    for (int i = 1; i <= N; i++) {
        cin >> red >> green >> blue;
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + green;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + blue;
    }
    int mn = min(dp[N][0], dp[N][1]);
    cout << min(dp[N][2], mn);
}
