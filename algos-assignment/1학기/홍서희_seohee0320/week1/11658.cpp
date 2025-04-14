#include <iostream>
using namespace std;;

int a[1025][1025];
int b[1025][1025];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
	  fill(a[0],a[0]+1025*1025,0);
    fill(b[0],b[0]+1025*1025,0);

  	for(int i = 1; i <= n; i++){
          for(int j = 1; j <= n; j++){
              cin>>a[i][j];
              b[i][j] = b[i][j - 1] + a[i][j];
          }
  	}
  
  	for(int i = 1; i <= m; i++){
          int type;
          cin>>type;
          if(type){
              int y1, x1, y2, x2;
              cin>>y1>>x1>>y2>>x2;
              int ret = 0;
              for(int j = y1; j <= y2; j++){
                  ret += (b[j][x2] - b[j][x1 - 1]);
              }
              cout<<ret<<"\n";
          }else{
              int y, x, value;
              cin>>y>>x>>value;
              int update_value = value - (b[y][x] - b[y][x - 1]);
              for(int j = x; j <= n; j++){
                  b[y][j] += update_value;
              }
          }
  	}
  	return 0;
}
