/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<deque>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
deque<int>Q;
int a[1000005];
int main(){
	int m=read(),cnt=1;
	a[cnt]=read();
	while(a[cnt]!=-1){
		while(Q.size()&&(int)Q.front()<cnt-m+1)Q.pop_front();
		while(Q.size()&&a[Q.back()]<=a[cnt])Q.pop_back();
		Q.push_back(cnt);
		if(cnt>=m)printf("%d\n",a[Q.front()]);
		a[++cnt]=read();
	}
}