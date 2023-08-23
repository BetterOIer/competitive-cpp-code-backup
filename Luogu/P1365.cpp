/*=================================================
* Le vent se lève, il faut tenter de vivre! 
世上只有一种英雄主义，那就是认清生活然后去热爱生活。 --米开朗基罗传
* Author: Better_OIer Zyx
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
long double len,f[300005];
string s;int l;
int main(){
    l=read();cin>>s;
	for(int i=1;i<=l;i++){
		switch(s[i-1]){
			case 'x':f[i]=f[i-1];len=0;break;
			case 'o':f[i]=f[i-1]+2*len+1;len++;break;
			case '?':f[i]=f[i-1]+len+0.5;len=(len+1)/2;break;
		}
	}
	printf("%.4Lf",f[l]);
}