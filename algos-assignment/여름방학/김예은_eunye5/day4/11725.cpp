#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];   // 인접 리스트
int parent[MAX];          // 부모를 저장할 배열
bool visited[MAX];        // 방문 체크

void dfs(int node) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            parent[next] = node;   // 부모 기록
            dfs(next);             // 재귀 탐색
        }
    }
}

int main() {
    int N;
    cin >> N;

    // 간선 입력 받기
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    // 부모 출력
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
}
