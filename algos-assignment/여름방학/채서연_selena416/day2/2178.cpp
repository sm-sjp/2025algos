#include <bits/stdc++.h>
using namespace std;

int N, M;
int maze[101][101];
int dist[101][101];
bool visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0';
        }
    }

    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1; // 시작 칸 포함

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (maze[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[N-1][M-1] << "\n";
    return 0;
}
