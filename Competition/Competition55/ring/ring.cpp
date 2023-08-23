/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 荷尔蒙决定一见钟情，多巴胺决定天长地久。 --网易云
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[100005],ans=2147483647;;
int main(){
    int n=read(),m=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i = 1;i<=n-m+1;i++) ans=min(ans,a[i+m-1]-a[i]);
    cout<<ans<<endl;
}