#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN=5000010;
const int INF=0x3f3f3f3f;
struct node
{
    int next;
    int to;
    int w;
} t[MAXN];
struct Qnode{
    int w;
    int po;
    inline bool operator <(const Qnode &x)const{
        return w>x.w;
    }
};
priority_queue<Qnode>q;
bool vis[MAXN];
int head[MAXN],num;
int dis[MAXN];
int n,m,k;
int ans=INF;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
inline void add(int x,int y,int z)
{
    t[++num].next=head[x];
    t[num].to=y;
    t[num].w=z;
    head[x]=num;
}
int main()
{
    freopen("radiant.in","r",stdin);
    freopen("radiant.out","w",stdout);
    int x,y,z,p,o,b;
    n=read(),m=read(),k=read(),p=read(),o=read(),b=read();
    for(int i=1; i<=m; i++)
    {
        x=read(),y=read(),z=read();
        for(int j=0;j<=k;j++)
        {
            add(x+n*j,y+n*j,z),add(y+n*j,x+n*j,z);
            if(j<k)add(x+n*j,y+n*(j+1),floor(z*p/o)+b),add(y+n*j,x+n*(j+1),floor(z*p/o)+b);
        }
    }
    memset(dis,INF,sizeof(dis));
    dis[1]=0;
    q.push((Qnode){0,1});
    while(!q.empty())
    {
        Qnode no=q.top();
        q.pop();
        int now=no.po;
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=head[now],y;i;i=t[i].next )
        {
            y=t[i].to;
            if(dis[y]>dis[now]+t[i].w)
            {
                dis[y]=dis[now]+t[i].w;
                q.push((Qnode){dis[y],y});
            }
        }
    }
    for(int i=0;i<=k;i++) ans=min(ans,dis[n+i*n]);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}