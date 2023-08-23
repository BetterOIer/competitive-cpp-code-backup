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
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long cf[10005],ans[10005],ANS=0;
int main(){
   	long long n=read();
   	for(long long i = 1,a,b;i<=n;i++){
		a=read(),b=read();
		cf[a]++,cf[b]--;
   	}
	for(long long i = 1;i<=10001;i++){
		ans[i]=ans[i-1]+cf[i];
		ANS=max(ANS,ans[i]);
	}
	cout<<ANS<<endl;
   	return 0;
}