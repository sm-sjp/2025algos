#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<ll,ll>pll;

ll ccw(pll A, pll B, pll C){
    return A.X*B.Y+B.X*C.Y+C.X*A.Y-A.Y*B.X-B.Y*C.X-C.Y*A.X;
}

void convexHull(vector<pll>&v){
    sort(v.begin(),v.end());
    vector<pll>L,R;
    for(pll i : v){
        while(L.size()>=2&&ccw(L[L.size()-2],L[L.size()-1],i)<=0){
            L.pop_back();
        }
        L.emplace_back(i);
         while(R.size()>=2&&ccw(R[R.size()-2],R[R.size()-1],i)>=0){
            R.pop_back();
        }
        R.emplace_back(i);    
    }
    v.clear();
    for(int i=0;i<L.size()-1;i++)v.emplace_back(L[i]);
    for(int i=R.size()-1;i>0;i--){
        v.emplace_back(R[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n;
    vector<pll>inp;
    for(int i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        inp.emplace_back(x,y);
    }
    convexHull(inp);
    cout<<inp.size()<<'\n';
    
    return 0;
}
