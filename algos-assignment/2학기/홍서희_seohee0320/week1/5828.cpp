#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>>v;

int main() {
    int N,G,B,D;
    cin>>N>>G>>B>>D;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    v.push_back({D,0});
    N = v.size();
    
    if(v[0].first>B){
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=1;i<N;i++){
        if(v[i].first-v[i-1].first>G){
            cout<<-1<<'\n';
            return 0;
        }
    } 
    vector<int>next(N,-1);
    stack<int>st;
    for(int i=0;i<N;i++){
        while(!st.empty()&&v[st.top()].second>v[i].second){
            next[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    int curFuel=B;
    ll cost=0;
    int prev=0;
    for(int i=0;i<N;i++){
        curFuel-=(v[i].first-prev);
        prev=v[i].first;
        if(curFuel<0){
            cout<<-1;
            return 0;
        }
        ll need=LLONG_MAX;
        if(next[i]!=-1){
            need=v[next[i]].first-v[i].first;
        }
        ll target=(need<=G?need:G);
        if(curFuel<target){
            ll buy=target-curFuel;
            curFuel+=buy;
            cost+=buy*v[i].second;
        }
    }
    cout<<cost;
    return 0;
}
