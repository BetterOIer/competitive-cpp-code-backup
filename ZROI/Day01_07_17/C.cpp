/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod = 1e9+7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int fa[100005][22];
int find(int x,int k){
    if(fa[x][k]==x)return x;
    else return fa[x][k]=find(fa[x][k],k);
}
void join(int x,int y,int k){
    fa[find(x,k)][k]=fa[find(y,k)][k];
}
int main(){
    n=read(),m=read();
    int md=log2(n);
    for(int i = 1; i <= n; ++i)
		for(int k = 0; k <= md; ++k)
			fa[i][k] = i;
    for(int i = 1,l1,r1,l2,r2;i<=m;i++){
        l1=read(),r1=read(),l2=read(),r2=read();
        for(int k = md;k>=0;k--){
            if(l1+(1<<k)-1<=r1)join(l1,l2,k),l1+=1<<k, l2+=1<<k;
        }
    }
    for(int k = md;k>0;k--){
        for(int i =1;i+(1<<k)-1<=n;i++){
            join(i,find(i,k),k-1),join(i+(1<<(k-1)),find(i,k)+(1<<(k-1)),k-1);
        }
    }
    long long ans=0;
    for(int i = 1;i<=n;i++){
        if(fa[i][0]==i) ans = !ans? 9:ans*10%mod;
    }
    cout<<ans<<endl;
    return 0;
}