/*=================================================
* le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
过去的不再回来，回来的不再美好。 --原创
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,l,r;
int a[200005],f[200005],ans;
priority_queue<int>q1,q;
int main(){
    n=read(),l=read(),r=read();
    for(int i=0;i<=n;i++)a[i]=read();
    for(int i=1;i<l;i++)q.push(a[i]);
    for(int i=l;i<=n;i++){
        q1.push(f[i-l]);
        if(i-r-1>=l)q.push(f[i-r-1]);
        while(!q.empty()&&q1.top()==q.top()) q1.pop();q.pop();
        f[i]=q1.top()+a[i];            
    }
    for(int i=n-r+1;i<=n;i++)ans=max(ans,f[i]);
    printf("%d",ans);
}