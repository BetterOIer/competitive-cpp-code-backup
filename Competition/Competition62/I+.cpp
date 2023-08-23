#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a[100];
ll n,f[2][100][100][100];
//    lim len mv num
ll dfs(ll len,ll mv,ll num,ll mod,bool limit){
    if(!len) return (!mv)&&(num==mod);
    if(~f[limit][len][mv][num])return f[limit][len][mv][num];
    ll res=0;
    ll maxn=limit?a[len]:1;
    for(ll i=0;i<=maxn;i++){
        res+=dfs(len-1,(mv*2+i)%mod,num+i,mod,limit&(i==maxn));
    }
    return f[limit][len][mv][num]=res;
}
ll solve(ll x){
    ll cnt=0;
    while(x){
        a[++cnt]=x&1;
        x>>=1;
    }
    ll ans=0;
    for(ll i=1;i<=64;++i){
        memset(f,-1,sizeof(f));
        ans+=dfs(cnt,0,0,i,1);
    }
    return ans;
}
int main(){
    cin>>n;
    cout<<solve(n);
}