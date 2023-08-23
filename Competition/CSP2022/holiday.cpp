#include<vector>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
inline long long read(){
    char c=getchar();long long x=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m,k;
long long score[2505]; 
bool vis[2505],v[2506],d[2506];
vector<int>ro[2505];
int dis[2506][2506];
struct node{
    int po;
    int val;
    bool operator < (const node &w)const{
        return w.val < val;
    }
};
priority_queue<node>Q;
long long ans=0;
void Dji(int s){
	dis[s][s]=0;
	memset(v,0,sizeof v);
    Q.push((node){s,0});
    v[s]=true;
    while(Q.size()){
        node now=Q.top();Q.pop();
        v[now.po]=true;
        for(int i:ro[now.po]){
            if(v[i])continue;
            if(dis[s][i]>now.val+1){
                dis[s][i]=now.val+1;
                Q.push((node){i,now.val+1});
            }
        }
    }
}
void dfs(int po,int step,long long val){
    if(!d[po])Dji(po),d[po]=true;
    if(step==5){
    	if(dis[po][1]<=k+1)ans=max(ans,val);
    }
    for(int i = 2;i<=n;i++){
        if((!vis[i])&&dis[po][i]<=k+1){
            vis[i]=true;
            dfs(i,step+1,val+score[i]);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);
    n=read(),m=read(),k=read();
    memset(dis,0x3f3f3f,sizeof dis);
    for(int i = 2;i<=n;i++)score[i]=read();
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
        //dis[x][y]=dis[y][x]=1;
    }
    vis[1]=true;
    dfs(1,1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}