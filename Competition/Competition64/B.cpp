/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
long long val[1000005][2];
long long cols[1000005];
long long costs[1000005];
long long nowCOL[1000005][2];
long long ANS=9223372036854775807ll;
struct node{
    long long cf;
    long long idx;
}Cf[100005];
vector<long long>tr[100005];
bool dfs(long long pos,long long fa){
    for(long long to:tr[pos]){
        if(to==fa)continue;
        bool status=dfs(to,pos);
        if(!status)return false;
        nowCOL[pos][0]+=nowCOL[to][0];
        nowCOL[pos][1]+=nowCOL[to][1];
        costs[pos]+=costs[to];
    }
    if(abs(nowCOL[pos][1]-nowCOL[pos][0])>1)return false;
    nowCOL[pos][cols[pos]]++;
    costs[pos]+=val[pos][cols[pos]];
    return true;
}
void dfs1(long long whi,long long col){
    if(whi>n){
        memset(costs,0,sizeof costs);
        memset(nowCOL,0,sizeof nowCOL);
        if(dfs(1,0)){
            ANS=min(ANS,costs[1]);
        }
        return;
    }
    cols[whi]=col;
    dfs1(whi+1,1);
    dfs1(whi+1,0);
}
bool cmp(node a, node b){
    return abs(a.cf)>abs(b.cf);
}
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        val[i][0]=read();
        val[i][1]=read();
        Cf[i].cf=val[i][0]-val[i][1];
        Cf[i].idx=i;
    }
    for(long long i = 1,u,v;i<n;i++){
        u=read(),v=read();
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    if(tr[1].size()==n-1){
        sort(Cf+2,Cf+n+1,cmp);
        long long R=0,B=0,ans=0,js=(n-1)&1;
        for(long long i = 2;i<=n;i++){
            if(R>=(n-1)/2&&!js)ans+=val[Cf[i].idx][0],B++;
            else if(B>=(n-1)/2&&!js)ans+=val[Cf[i].idx][1],R++;
            else if(R>(n-1)/2&&js)ans+=val[Cf[i].idx][0],B++;
            else if(B>(n-1)/2&&js)ans+=val[Cf[i].idx][1],R++;
            else ans+=min(val[Cf[i].idx][1],val[Cf[i].idx][0]),(val[Cf[i].idx][1]>val[Cf[i].idx][0]? B++:R++);

        }
        cout<<ans+min(val[1][0],val[1][1])<<endl;
        return 0;
    }
    dfs1(0,0);
    cout<<ANS;
    return 0;
}