#include <iostream>
#include <vector>
using namespace std;

int N;
int input[11];
int op[4] = {0 , }; // 연산자 개수 저장, + - x / 순서
int minNum = 1000000000;
int maxNum = -1000000000;

// 백트래킹으로 가능한 연산자 순열 구조 구하기
void backtracking(int depth, int sum){
	
	if(depth == N-1){
		if(sum > maxNum) maxNum = sum;
    	if(sum < minNum) minNum = sum;
	}
        
    if(op[0]>0){
        op[0]--;
        backtracking(depth+1, sum + input[depth+1]);
        op[0]++;
    }
    if(op[1]>0){
       op[1]--;
       backtracking(depth+1, sum - input[depth+1]);
       op[1]++;
    }
    if(op[2]>0){
       op[2]--;
       backtracking(depth+1, sum * input[depth+1]);
       op[2]++;
    }
    if(op[3]>0){
       op[3]--;
       backtracking(depth+1, sum / input[depth+1]);
       op[3]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> input[i];
    }
    
    // 연산자 입력받기
    for(int i=0; i<4; i++){
        cin >> op[i];
    }
    
    backtracking(0, input[0]);
    
    cout << maxNum << "\n" << minNum << "\n";
}
