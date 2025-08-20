#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int N, M; 
int count = 0;
bool visited[MAX];

// 인접 리스트 방식으로 그래프 표현 (각 인덱스는 노드 번호)
vector<int> network[MAX];

// 깊이 우선 탐색
void dfs(int x){
	
	if(visited[x] == false)
		count++;
		
    visited[x] = true;
    
    // 현재 노드에 인접한 모든 노드 탐색
    for(int i=0; i< network[x].size(); i++){
        
        int y = network[x][i];
        if(!visited[y]){
            dfs(y); // 해당 노드에 대해 재귀적으로 탐색
        }
    }
    
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin >> M;
    
    for(int i=0; i<M; i++){
        int parent, child;
        cin >> parent >> child;
        network[parent].push_back(child);
        network[child].push_back(parent); // 양방향
    }
    
    dfs(1);
    
    cout << count - 1; // 1번 컴퓨터 제외
    
	return 0;
}
