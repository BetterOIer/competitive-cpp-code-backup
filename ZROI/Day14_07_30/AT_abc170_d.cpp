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
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,ans;
bool vis[1000005];
int a[1000005];
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(!vis[a[i]]){
			if(a[i]!=a[i+1]) ans++;
			for(int j=1;a[i]*j<=1000000;j++) vis[a[i]*j]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
