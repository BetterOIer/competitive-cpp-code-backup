/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 我有一个梦，也许有一天，灿烂的阳光能照进黑暗森林。 --三体
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
int fa[300003],front[300003],len[300003];
char opt;
int find(int x){
    if(x==fa[x]) return x;
    int fn=find(fa[x]);
    front[x]+=front[fa[x]];
    return fa[x]=fn;
}
void join(int a,int b){
    int ffa=find(a),ffb=find(b);
    front[ffa]+=len[ffb];
    fa[ffa]=ffb;
    len[ffb]+=len[ffa];
    len[ffa]=0;
}
int main(){
    int n=read();
    for(int i = 1;i<=300000;i++) fa[i]=i,front[i]=0,len[i]=1;
    for(int i = 1,a,b;i<=n;i++){
        cin>>opt;a=read(),b=read();
        if(opt=='M') join(a,b);
        else cout<<(find(a)==find(b)? abs(front[a]-front[b])-1:-1)<<endl;
    }
}