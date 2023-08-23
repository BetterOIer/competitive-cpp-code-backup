/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 因为痛苦太有价值，因为回忆太珍贵，所以我们更要继续往前走。 --五月天
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n;
long long a[2000005],b[2000005],c[2000005];
int main(){
    long long T=read();
    while(T--){
        n=read();
        long long ans=0;
        for(long long i = 1;i<=n;i++)a[i]=read();
        for(long long i = 1;i<=n;i++){a[i]-=read();if((a[i]&1)==1)ans=1-ans;} 
        cout<<ans<<endl;
    }
}