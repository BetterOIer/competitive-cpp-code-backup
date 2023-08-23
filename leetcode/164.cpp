/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 你的死亡让我的掉败更加沉重！ --堕降的瓦拉斯塔兹
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[1000005],maxn=0,minn=2147483647;
struct node{
    int maxn=-1;
    int minn=-1;
}b[1000005];
int main(){
    int n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        maxn=max(a[i],maxn);
        minn=min(a[i],minn);
    }
    int ge=ceil(1.0*(maxn-minn)/(n+1));
    for(int i = 1;i<=n;i++){
        int belong =ceil( 1.0*a[i]/ge);
        if(b[belong].maxn==-1){
            b[belong].maxn=b[belong].minn=a[i];
        }else{
            b[belong].maxn=max(a[i],b[belong].maxn);
            b[belong].minn=max(a[i],b[belong].minn);
        }
    }
    int answer=0;
    int nearby=0;
    for(int i = 1;i<=n+1;i++){
        if(b[i].maxn==-1){
            continue;
        }
        if(nearby==0){
            nearby=i;
            continue;
        }
        answer=max(answer,b[i].minn-b[nearby].maxn);
        nearby=i;
    }
    cout<<answer;
}