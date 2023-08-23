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
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,k,e,d,p=1,q=1;
bool down[606];
priority_queue<int, vector<int>, greater<int>>nex[22];
struct Qnode{
    int pos;
    int val;
    int nex;
};
struct node{
    int to;
    int val;
    int idx;
};
vector<node>ro[105];
struct crash{
    int whi;
    int tim;
}st[606],en[606];
bool cmp(crash a,crash b){
    return a.tim<b.tim;
}
void got_crashed(int whi){
    nex[whi].pop();
    for(auto i:ro[whi]){
        down[i.idx]=true;
    }
}
void got_fixed(int whi){
    for(auto i:ro[whi]){
        down[i.idx]=false;
    }
}
int main(){
    n=read(),m=read(),k=read(),e=read();
    for(int i = 1,u,v,w;i<=e;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w,i});
        ro[v].push_back((node){u,w,i});
    }
    d=read();
    for(int i = 1;i<=d;i++){
        st[i].whi=en[i].whi=read();
        st[i].tim=read();
        en[i].tim=read()+1;
        nex[st[i].whi].push(st[i].tim);
    }
    for(int i = 1;i<=m;i++)nex[i].push(2147483647);
    sort(st+1,st+d+1,cmp);sort(en+1,en+d+1,cmp);
    int TIM=1;
    long long ANS=0;
    while(TIM<=n){
        while(p<=d&&q<=d&&(st[p].tim<=TIM||en[q].tim<=TIM)){
            if(st[p].tim<=en[q].tim)got_crashed(st[p].whi),p++;
            else got_fixed(en[q].whi),q++;
        }
        queue<Qnode>Q;
        int ans=2147483647,ne;
        Q.push((Qnode){1,0,n+1});
        while(Q.size()){
            Qnode now = Q.front();Q.pop();
            if(now.val>ans)continue;
            if(now.pos==m){
                if(ans>now.val){
                    ans=now.val;
                    ne=now.nex;
                }
                continue;
            }
            for(auto to:ro[now.pos]){
                if(down[to.idx])continue;
                Q.push((Qnode){to.to,now.val+to.val,min(now.nex,nex[to.to].top())});
            }
        }
        ANS+=ans*(min(ne,n+1)-TIM)+k;
        TIM=ne;
    }
    cout<<ANS;
    return 0;
}