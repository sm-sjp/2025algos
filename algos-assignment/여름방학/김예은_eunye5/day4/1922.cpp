#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, cost;
};

int parent[1001];

// find 함수 (경로 압축)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// union 함수 (두 집합 합치기)
bool union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;  // 이미 같은 집합이면 사이클
    if (a < b) parent[b] = a;
    else parent[a] = b;
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);

    // 간선 입력
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // 부모 배열 초기화
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    // 간선 정렬 (비용 기준 오름차순)
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
        });

    int totalCost = 0;
    int edgeCount = 0;

    // 작은 간선부터 확인
    for (auto& e : edges) {
        if (union_set(e.u, e.v)) {  // 사이클이 안 생기면 선택
            totalCost += e.cost;
            edgeCount++;
            if (edgeCount == N - 1) break;  // MST 완성
        }
    }

    cout << totalCost << "\n";
}
