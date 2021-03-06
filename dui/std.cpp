#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int T; std::cin>>T;
    while(T--){
        ll x,y; std::cin>>x>>y;
        ll a,b,c; std::cin>>a>>b>>c;
        std::map<ll,ll>mp;
        std::queue<ll>q; q.push(x);
        mp[x]=0;
        while(!q.empty()){
            ll u=q.front(); q.pop();
            if(u>4*std::max(x,y)) continue;
            // pr(u,mp[u]);
            ll v=u+1;
            if(!mp.count(v)||mp[v]>mp[u]+a) q.push(v), mp[v]=mp[u]+a;
            v=2*u;
            if(!mp.count(v)||mp[v]>mp[u]+b) q.push(v), mp[v]=mp[u]+b;
            v=u/2;
            if(!mp.count(v)||mp[v]>mp[u]+c) q.push(v), mp[v]=mp[u]+c;
        }
        std::cout<<mp[y]<<'\n';
    }
    return 0;
}