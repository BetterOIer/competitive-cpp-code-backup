/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
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
int a[10000006];
void solve(){
    int n=read(),m=read(),last=0;
    for(int i= 0;i<m;i++) a[i]=read();
    for(int i= 2;i<=n;i++) last=(last+a[(n-i)%m])%i;
    cout<<last<<endl;
}
int main(){
    int t=read();
    while(t--)solve();
}