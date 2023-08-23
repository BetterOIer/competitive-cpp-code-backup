#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int mod = 100000007;
int a[100005];
struct ope{
    int whi;
    int opt;
    int ch;
    int inf;
}way[100005];
bool cmp(ope a,ope b){
    return a.inf>b.inf;
}
int main(){
    int k=read(),n=read(),m=read();
    for(int i =1;i<=k;i++){
        a[i]=read();
    }
    int tot=0;
    for(int i = 1;i<=n;i++){
        way[++tot].opt=read();
        way[tot].whi=read();
        way[tot].ch=read();
        way[tot].inf=(way[tot].opt==1? way[tot].ch-a[way[tot].whi]:(way[tot].opt==2? way[tot].ch:a[way[tot].whi]*(way[tot].ch-1)));
        if(way[tot].inf<0)tot--;
    }
    sort(way+1,way+1+tot,cmp);
    m=min(m,tot);
    for(int i = m;i>=1;i--){
        a[way[i].whi]=(way[i].opt==1? way[i].ch%mod:(way[i].opt==2? (a[way[i].whi]+way[i].ch)%mod:(long long)a[way[i].whi]*way[i].ch%mod));
    }
    long long ans=1;
    for(int i = 1;i<=k;i++){
        ans=ans*a[i]%mod;
    }
    cout<<ans;
}