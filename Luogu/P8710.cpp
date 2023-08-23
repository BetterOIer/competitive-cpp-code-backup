/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 唯有再见方为人生。 --人间失格·Goodbye
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int fa[10005],d[10005],ans[10005];
int find(int x){
    if(fa[x]==x) return x;
    int nf=find(fa[x]);
    d[x]+=d[fa[x]];
    return fa[x]=nf;
}
int main(){
    int n=read(),m=read();
    for(int i = 1;i<=n;i++) fa[i]=i;
    for(int i = 1,num,x,y,fx,fy;i<=m;i++){
        num=read(),x=read(),y=read();
        if(num==1){
            fx=find(x),fy=find(y);
            if(fx==fy) continue;
            d[fx]+=ans[fx]-ans[fy];
            fa[fx]=fy;
        }
		else ans[find(x)]+=y;
    }
    for(int i=1;i<=n;i++) cout<<ans[find(i)]+d[i]<<" ";
}