/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 智慧需要沉淀，积累才能够饱满。
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
/* #include<iostream>
#include<deque>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n;
long long h[200050],ans=0;
struct node{
    long long h;
    long long w;
};
deque <node> S;
void solve(){
    ans=0;
    S.clear();
    S.push_back((node){0,0});
    for(long long i=1;i<=n+1;i++){
        if(h[i]>S.back().h)S.push_back((node){h[i],1});
        else{
            long long wid=0;
            while(S.back().h>h[i]){
                wid+=S.back().w;
		   	    ans=max(ans,1ll*wid*S.back().h);
		   	    S.pop_back();
            }
            S.push_back((node){h[i],wid+1});
        }
    }
    cout<<ans<<endl;
}
int main(){
    n=read();
    while(n){
        for(long long i=0;i<=200006;i++)h[i]=0;
        for(long long i = 1;i<=n;i++)h[i]=read();
        solve();
        n=read();
    }
} */
