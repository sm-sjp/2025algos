#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[600][600];
char arr[600][600];
int n, m;
int cnt = 0;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // nx,ny 범위 주의하기
        if (!visited[nx][ny] && arr[nx][ny] != 'X' && nx >= 0 && ny >= 0 &&
            nx < n && ny < m) {
            if (arr[nx][ny] == 'P') cnt++;
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int start_x, start_y;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'I') {
                start_x = i;
                start_y = j;
            }
        }
    }
    visited[start_x][start_y] = true;
    dfs(start_x, start_y);
    if (cnt == 0)
        cout << "TT";
    else
        cout << cnt;
    return 0;
}
