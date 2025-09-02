#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[1000][1000];
    int dp[1000][1000];  // 넓이가 아닌 길이를 dp로 저장
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;  // 한 줄 입력
        for (int j = 0; j < m; j++) arr[i][j] = s[j] - '0';
    }
    // dp값 초기화
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i][0] = arr[i][0];
        ans = max(ans, dp[i][0]);
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = arr[0][j];
        ans = max(ans, dp[0][j]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 1) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;  
              // 위,왼쪽, 왼쪽 대각선 값을 비교해서 가장 작은 값에 1 더하기
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans;

    return 0;
}
