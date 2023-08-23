/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 未期之遇，不告而别。闻所闻而来，见所见即去。 --老巴塔哥尼亚快车
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
#include<set>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,m,k;
struct node{
    long long x;
    long long y;
    long long val;
};
queue<node>Q;
set<long long>hi;
long long graph[3005][3005];
long long dis[3005][3005];
bool vis[3005][3005];
long long dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
long long K[9000005][2];
long long kdis[9000005][2];
int main(){
    freopen("dream5.in","r",stdin);
    n=read(),m=read(),k=read();

    for(long long i = 1;i<=n;i++){
        for(long long j = 1;j<=m;j++){
            graph[i][j]=read();
            dis[i][j]=2147483647;
        }
    }
    for(long long i = 1;i<=k;i++){
        K[i][0]=read(),K[i][1]=read();
    }
    Q.push((node){1,1,0});
    while(Q.size()){
        node now = Q.front(),nex;Q.pop();
        dis[now.y][now.x]=min(dis[now.y][now.x],now.val);
        vis[now.y][now.x]=true;
        for(long long i = 0;i<4;i++){
            if(now.y+dir[i][0]>n||now.y+dir[i][0]<1||now.x+dir[i][1]>m||now.x+dir[i][1]<1||vis[now.y+dir[i][0]][now.x+dir[i][1]]==true||graph[now.y+dir[i][0]][now.x+dir[i][1]]==0)continue;
            nex.x=now.x+dir[i][1],nex.y=now.y+dir[i][0],nex.val=now.val+1;
            Q.push(nex);
        }
    }
    long long fh=2147483647,fwh=0;
    for(long long i = 1;i<=k;i++)kdis[i][0]=dis[K[i][0]][K[i][1]];
    for(long long i = 1;i<=k;i++){
        if(kdis[i][0]>fh) continue;
        else if(kdis[i][0]<fh){
            hi.clear();
            fh=kdis[i][0],fwh=i;
            if(hi.find(graph[K[fwh][0]][K[fwh][1]])==hi.end())hi.insert(graph[K[fwh][0]][K[fwh][1]]);
        }
        else{
            if(hi.find(graph[K[i][0]][K[i][1]])==hi.end())hi.insert(graph[K[i][0]][K[i][1]]);
        }
    }
    long long ans=dis[n][m];

    for(long long i = 1;i<=n;i++){
        for(long long j = 1;j<=m;j++){
            dis[i][j]=2147483647;
            vis[i][j]=false;
        }
    }
    Q.push((node){n,m,0});
    while(Q.size()){
        node now = Q.front(),nex;Q.pop();
        dis[now.y][now.x]=min(dis[now.y][now.x],now.val);
        vis[now.y][now.x]=true;
        for(long long i = 0;i<4;i++){
            if(now.y+dir[i][0]>n||now.y+dir[i][0]<1||now.x+dir[i][1]>m||now.x+dir[i][1]<1||vis[now.y+dir[i][0]][now.x+dir[i][1]]==true||graph[now.y+dir[i][0]][now.x+dir[i][1]]==0)continue;
            nex.x=now.x+dir[i][1],nex.y=now.y+dir[i][0],nex.val=now.val+1;
            Q.push(nex);
        }
    }
    long long sh=2147483647;
    bool can=false;;
    for(long long i = 1;i<=k;i++)kdis[i][1]=dis[K[i][0]][K[i][1]];
    for(long long i = 1;i<=k;i++){
        if(kdis[i][1]>sh) continue;
        else if(kdis[i][1]<sh){
            sh=kdis[i][1];
            if(hi.find(graph[K[i][0]][K[i][1]])==hi.end())can=false;
            else can=true;
        }
        else{
            if(!can)if(hi.find(graph[K[i][0]][K[i][1]])!=hi.end())can=true;
        }
    }
    cout<<min(ans,sh+fh+1+(long long)(!can));
}