#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,pair<int,int>>pi;
#define X first
#define Y second

vector<string>ans;
vector<pi>query;
int p[200001], v[200001];

int find(int a){
    if(p[a]==a)return a;
    return p[a]=find(p[a]);
}
void Union(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b)return;
    p[a]=b;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n,m,q;
    cin>>n>>m;
    q=n+m;
    for(int i=2;i<=n;i++)cin>>v[i];
    for(int i=0;i<q;i++){
        int x,a,b;
        cin>>x;
        if(x==0){
            cin>>a;
            query.push_back({x,{a,0}});
        }
        else{
            cin>>a>>b;
            query.push_back({x,{a,b}});
        }
    }
    for(int i=1;i<=n;i++)p[i]=i;
    reverse(query.begin(),query.end());
    for(auto i :query){
        if(i.X==0) Union(i.Y.X,v[i.Y.X]);
        if(i.X==1){
            if(find(i.Y.X)==find(i.Y.Y))ans.push_back("YES");
            else ans.push_back("NO");
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i : ans) cout<<i<<"\n";
    return 0;
}
