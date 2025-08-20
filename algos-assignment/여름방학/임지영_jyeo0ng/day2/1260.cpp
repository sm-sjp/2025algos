#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

vector<int> graph[1001]; // 노드 간 관계를 인접 리스트로 구현
queue<int> q;

bool visited_dfs[1001];
bool visited_bfs[1001];


void dfs(int x){
    // 화면에 노드 출력
    cout << x << " ";
    visited_dfs[x] = true;
    
    // 해당 노드의 인접 노드 확인
    for(int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        
        if(!visited_dfs[y]){
            dfs(y);
        }
    }
}

void bfs(int x){
    visited_bfs[x] = true;
    q.push(x); // 큐에 방문한 노드 추가
    
    while(!q.empty()){
    	int node = q.front();
    	q.pop();
    	cout << node << " ";

      // 큐에서 꺼낸 노드의 인접 노드 확인
    	for(int i=0; i<graph[node].size(); i++){
    		int y = graph[node][i];
    		
    		// 방문하지 않은 노드라면 큐에 삽입
    		if(!visited_bfs[y]){
    			q.push(y);
    			visited_bfs[y] = true;
    		}
    	}
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> V;
    
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // 양방향
    }
    
    // 오름차순 정렬
    for(int i=0; i<1001; i++){
		sort(graph[i].begin(), graph[i].end());
    	
    }
    
    dfs(V);
    cout << "\n";
    bfs(V);
    
}
