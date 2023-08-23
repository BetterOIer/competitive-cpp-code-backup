#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n;
struct node{
    int to;
    bool can;
};
int rebui[200005];
vector <node> ro[200005];
int k[200005];
void dfs1(int pos,int fa){
    for(node to:ro[pos]){
        if(to.to==fa)continue;
        dfs1(to.to,pos);
        rebui[pos]+=rebui[to.to]+(int)(!to.can);
    }
}
void dfs2(int pos,int fa,bool can){
    k[pos]=k[fa]+can*1+(!can)*(-1);
    for(node to:ro[pos]){
        if(to.to==fa)continue;
        dfs2(to.to,pos,to.can);
    }
}
void init(){
    for(int i = 0;i<200005;i++){
        rebui[i]=k[i]=0;
        ro[i].clear();
    }
}
int main(){
    while(cin>>n){
        init();
        for(int i = 1,x,y;i<n;i++){
            x=read(),y=read();
            ro[x].push_back((node){y,1});
            ro[y].push_back((node){x,0});
        }
        dfs1(1,0);
        k[1]=rebui[1];
        for(node to:ro[1]){
            dfs2(to.to,1,to.can);
        }
        int minn=2147483647;
        for (int i=1;i<=n;i++) if (minn>k[i]) minn=k[i];
        printf("%d\n",minn);
        for (int i=1;i<=n;i++) if (minn==k[i]) printf("%d ",i);
        puts("");
    }
}