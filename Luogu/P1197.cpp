#include<iostream>
#include<algorithm>
#define maxn 200005
using namespace std;
int n,m,fa[2*maxn],k,d[2*maxn],vis[maxn*2],ans[2*maxn],num;
struct pcw{
    int x,y,c;
    bool operator < (const pcw b)const{
        return c<b.c;
    }
}a[maxn];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void combine(int x,int y){
    int xf=find(x),yf=find(y);
    if(xf!=yf) fa[xf]=yf,num--;
}
int main(){
    n=read();
    m=read();
    num=n;
    for(int i = 0;i<n;i++){
        fa[i]=i;
    }
    for(int i = 1;i<=m;i++){
        a[i]=(pcw){read(),read(),0};
    }
    k=read();
    for(int i=1;i<=k;i++) {
        vis[d[i]=read()]=k-i+1;
    }
    for(int i=1;i<=m;i++) a[i].c=max(vis[a[i].x],vis[a[i].y]);
    sort(a+1,a+1+m);
    for(int i=0,j=1;i<=k;i++){
        for(;a[j].c==i;j++) combine(a[j].x,a[j].y);
        ans[i]=num-(k-i);
    }
    for(int i=k;i>=0;i--) printf("%d\n",ans[i]);
    return 0;
}