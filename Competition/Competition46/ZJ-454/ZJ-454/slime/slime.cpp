#include<iostream>
#include<cmath>
using namespace std;
long long n,k;
long long dfs(long long now,long long maxn){
    long long tim=ceil(1.0*(now-(maxn>>1))/k);
    long long tim2=ceil(1.0*now/k);
    if(tim==tim2)return 1;
    long long left=now-k*tim;
    return ((dfs(left,left))<<1)+tim;
}
long long main(){
    freopen("slime.in","r",stdin);
    freopen("slime.out","w",stdout);
    cin>>n>>k;
    cout<<dfs(n,n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}