/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 2e9+7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,s,t;
struct node{
    int to;
    int harm;
    int k_l;
    int k_r;
};vector<node>ro[20005];
struct Qnode{
    int pos;
    int min_life;
    int now_k;
};queue<Qnode>Q;
int main(){
    n=read(),m=read(),s=read(),t=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        for(int l = 1,r;l<=w;l=r+1){
            r=w/(w/l);
            ro[u].push_back((node){v,w/l,l,r});
            ro[v].push_back((node){u,w/l,l,r});
        }
        ro[u].push_back((node){v,0,w+1,INF});
        ro[v].push_back((node){u,0,w+1,INF});
    }
    Q.push((Qnode){t,0,0});
    int ans=INF;
    while(Q.size()){
        Qnode now = Q.front();Q.pop();
        if(now.min_life>ans)continue;
        if(now.pos==s){
            ans=min(ans,now.min_life);
            continue;
        }
        for(node to:ro[now.pos]){
            if(to.k_l>now.now_k+1||to.k_r<now.now_k+1)continue;
            if(to.harm==0){
                ans=min(ans,now.min_life);
                continue;
            }
            Q.push((Qnode){to.to,now.min_life+to.harm,now.now_k+1});
        }
    }
    cout<<ans<<endl;
    return 0;
}