#include <iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<climits>
using namespace std;

struct Route{
    int s,e,c;
};

bool cmp(Route r1, Route r2){
    if(r1.s==r2.s) return r1.e>r2.e;
    return r1.s<r2.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    vector<Route>v(n);
    for(int i=0;i<n;i++){
        int s,e,c;
        cin>>v[i].s>>v[i].e>>v[i].c;
    }
    sort(v.begin(),v.end(),cmp);
    vector<Route>r;
    Route temp={-1,-1,INT_MAX};
    for(auto &route : v){
        if(temp.e<route.s){
            r.push_back(temp);
            temp=route;
            continue;
        }
        temp.e=max(temp.e,route.e);
        temp.c=min(temp.c,route.c);
    }
    r.push_back(temp);
    cout<<r.size()-1<<"\n";
    for(int i=1;i<r.size();i++)cout<<r[i].s<<" "<<r[i].e<<" "<<r[i].c<<"\n";
    return 0;
}
