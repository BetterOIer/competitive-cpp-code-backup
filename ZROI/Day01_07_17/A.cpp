/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int tot=0,idx=0;
int fa[2000005];
map<int,int> sto;
struct REQ{
    int i;
    int j;
}req[2000005];
void init(){
    for(int i = 1;i<=2000000;i++)fa[i]=i;
    tot=idx=0;
    sto.clear();
}
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void join(int x,int y){
    fa[find(x)]=fa[find(y)];
}
bool same(int x,int y){
    if(find(x)==find(y))return true;
    return false;
}
int main(){
    int t=read();
    while(t--){
        init();
        int n=read();
        for(int i = 1,x,y,z;i<=n;i++){
            x=read(),y=read(),z=read();
            if(sto.find(x)==sto.end()){
                sto[x]=++idx;
                x=idx;
            }else{
                x=sto[x];
            }
            if(sto.find(y)==sto.end()){
                sto[y]=++idx;
                y=idx;
            }else{
                y=sto[y];
            }
            if(!z){
                req[++tot].i=x;
                req[tot].j=y;
            }else{
                join(x,y);
            }
        }
        int yes=true;
        for(int i = 1;i<=tot;i++){
            if(same(req[i].i,req[i].j)){yes=false;break;}
        }
        if(yes)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}