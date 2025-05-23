#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int map[101][101]; 
int visit[101][101];
int dx[] = {0, 0, -1, 1}; 
int dy[] = {1, -1, 0, 0}; 

void bfs() {
    deque<pair<int, int>> dq;
    dq.push_front({0, 0});
    visit[0][0] = 0;

    while (!dq.empty()) {
        auto [x, y] = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int cost = map[ny][nx]; // 0 or 1
                if (visit[ny][nx] > visit[y][x] + cost) {
                    visit[ny][nx] = visit[y][x] + cost;
                    if (cost == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    memset(visit, 0x3f, sizeof(visit));
    bfs();

    cout << visit[n - 1][m - 1] << '\n';
    return 0;
}
