#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int yy,xx,ny,nx;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

vector<vector<int>> bfs(vector<vector<char>>&a, int y, int x){
    int n = a.size();
    int m= a[0].size();
    vector<vector<int>> map(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) map[i][j]=-1;
    }
    map[y][x]=0;
    deque<pair<int,int>>q;
    q.push_front({y, x});
    while(!q.empty()){
        yy=q.front().first;
        xx=q.front().second;
        q.pop_front();
        for(int i=0;i<4;i++){
            ny=yy+dy[i];
            nx=xx+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(a[ny][nx]=='*')continue;
            if(map[ny][nx]!=-1) continue;
            if(a[ny][nx]=='#'){
                map[ny][nx]=map[yy][xx]+1;
                q.push_back({ny,nx});
            }
            else {
                map[ny][nx]=map[yy][xx];
                q.push_front({ny,nx});
            }
        }
    }
    return map;
}
int main(){
    int t; cin>>t;
    while(t--){
        int h,w;
        cin>>h>>w;
        vector<vector<char>>v(h+2,vector<char>(w+2));
        int y1=0,x1=0,y2=0,x2=0,tmp=0;
        int ans=987654321;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>v[i][j];
                if(v[i][j]=='$'&&y1==0){
                    y1=i; x1=j;
                }
                else if(v[i][j]=='$'&&y1!=0){
                    y2=i; x2=j;
                }
            }
        }
        vector<vector<int>>d1=bfs(v,0,0);
        vector<vector<int>>d2=bfs(v,y1,x1);
        vector<vector<int>>d3=bfs(v,y2,x2);
        
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(v[i][j]== '*'){
                    continue;
                }
                tmp=d1[i][j]+d2[i][j]+d3[i][j];
                if(d1[i][j]<0||d2[i][j]<0||d3[i][j]<0) continue;
                if(v[i][j]=='#')tmp-=2;
                if(ans>tmp) ans=tmp;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
