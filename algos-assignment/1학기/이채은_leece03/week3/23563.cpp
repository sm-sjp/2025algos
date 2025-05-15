#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
const int inf = INT_MAX;
pii dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int H, W; cin >> H >> W;
    string matrix[H]; for (int i = 0; i < H; i++) cin >> matrix[i];
    int si, sj, ei, ej, w[H][W]; 
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++){
        if (matrix[i][j] == '#'){ // 벽
            w[i][j] = 2;
            continue;
        }
        if (matrix[i][j] == 'S') // 시작
            si = i, sj = j;
        else if (matrix[i][j] == 'E') // 끝
            ei = i, ej = j;
        for (auto [di, dj]: dir) 
            if (0 <= i + di && i + di < H && 0 <= j + dj && j + dj < W && matrix[i + di][j + dj] == '#'){
                w[i][j] = 0;
                break;
            }
    }
    // BFS
    deque<tiii> dq; dq.push_back({0, si, sj}); 
    int distance[H][W]; fill(&distance[0][0], &distance[H - 1][W], inf);
    distance[si][sj] = 0;

    while (!dq.empty()){
        auto [d, i, j] = dq.front(); dq.pop_front();
        if (distance[i][j] < d) continue;
        for (auto [di, dj]: dir)
            if (0 <= i + di && i + di < H && 0 <= j + dj && j + dj < W){
                if (!w[i][j] && !w[i + di][j + dj]){ 
                    if (distance[i + di][j + dj] > d){
                        distance[i + di][j + dj] = d;
                        dq.push_front({d, i + di, j + dj}); 
                    }
                }
                else if (w[i + di][j + dj] != 2){ 
                    if (distance[i + di][j + dj] > d + 1){
                        distance[i + di][j + dj] = d + 1;
                        dq.push_back({d + 1, i + di, j + dj}); 
                    }
                }
            }
    }

    cout << distance[ei][ej];
}
