#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N; cin >> N;
	vector<int> input(N);
	
	for(int i=0; i<N; i++){
		int K; cin >> K;
		input[i] = K;
	}
	
	// 최댓값을 구하기 위해 vector 사용
	int max = *max_element(input.begin(), input.end());
	
	// 에라토스테네스의 체로 소수만을 저장한다.
	vector<int> prime(max+1);
	
	// 자기 자신의 수로 저장
	for(int i=0; i<max+1; i++)
		prime[i] = i;

	// 에라토스테네스의 체
	for(int i=2; i*i<=max; i++){
		if(prime[i] == i){
			for(int j=i*i; j<=max; j+=i){
				if(prime[j] == j)
				// 소수값을 저장한다. 
					prime[j] = i;
			}
		}
	}
	
	// 각 숫자에 대해 소인수분해
	for(int i=0; i<N; i++){
		int num = input[i];
		// 최종값이 1일때까지 나눈다 
		while(num>1){
			cout << prime[num] << " ";
			num /= prime[num];
		}
		cout << "\n";
	}
	
	return 0;
}
