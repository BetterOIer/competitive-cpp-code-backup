/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int dirx[4]={1,-1,0,0},diry[4]={0,0,1,-1};
int stax,stay,endx,endy;
int ANS=2147482647;
bool vis[20][20];
void dfs(int nowx,int nowy,int ans){
    if(nowx==endx&&nowy==endy){
        ANS=min(ANS,ans);
        return;
    }
    for(int i = 0;i<4;i++){
        int nex=nowx+dirx[i],ney=nowy+diry[i];
        if(((nex==1||nex==19)||(ney==1||ney==19))&&(1<=nex&&nex<=19)&&(1<=ney&&ney<=19)&&(!vis[nex][ney])){
            vis[nex][ney]=true;
            dfs(nex,ney,ans+1);
            vis[nex][ney]=false;
        }
    }
}
int main(){
    stax=read(),stay=read(),endx=read(),endy=read();
    dfs(stax,stay,0);
    cout<<ANS;
    return 0;
}