#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll fin[10000007],pr[10000007],num=0;
bool vis[10000007];
void find_f(int all){
    fin[1]=1;
    for(int i = 2;i<=10000000;i++){
        if(!vis[i]){
            fin[i]=i-1;
            pr[++num]=i;
        }
        for(int j = 1;j<=num&&pr[j]*i<=all;j++){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0){
                fin[pr[j]*i]=pr[j]*fin[i];
                break;
            }
            else fin[pr[j]*i]=fin[pr[j]]*fin[i];
        }
    }
}
ll fastpo(ll num,int x,int mo){
    ll ans=1;
    for(;x;x>>=1,num=1LL*num*num%mo) if(x&1) ans=1LL*ans*num%mo;
    return ans;
}
ll solve(int p){
    if(p==1) return 0;
    else return fastpo(2,solve(fin[p])+fin[p],p);
}
int main(){
    find_f(10000000);
    int T;
    cin>>T;
    for(;T--;) {
		int p;
		scanf("%d",&p);
		printf("%lld\n",solve(p));
	}
}