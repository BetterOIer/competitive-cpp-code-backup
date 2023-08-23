/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: http://betteroier.site:1000
* FileStation: http://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,q;
/*pair<int,int>edge[250000];
set<int>po[100005];
int ans[100005];
int main(){
    freopen("ex_tree4.in","r",stdin);
    freopen("ex_tree4.outt","w",stdout);
    n=read();
    for(int i = 1;i<n;i++)edge[i].first=read(),edge[i].second=read();
    q=read();
    for(int i = 1,size;i<=q;i++){
        size=read();
        for(int j = 1,k;j<=size;j++){
            k=read();
            po[i].insert(k);
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=q;j++){
            if(po[j].find(edge[i].first)!=po[j].end()&&po[j].find(edge[i].second)!=po[j].end())ans[j]++;
        }
    }
    for(int i = 1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
} */
/* int fa[2500005],size[2000005];
int find(int x){
    if(fa[x]==x)return x;
    else return find(fa[x]);
}
int join(int x,int y){
    if(size[x]>size[y]) fa[y]=x;
    else
    {
        if(size[x]==size[y]) size[y]++;  
        fa[x]=y;
    }
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        fa[i]=i;
    }
    for(int i = 1,x,y;i<=n;i++){
        x=read(),y=read();
        join(x,y);
    }
    q=read();
    for(int i = 1,idx;i<=q;i++){
        idx=read();
        for(int i = )
    }
    
    
    q=read();

} */
vector<int>ro[1000005];
bool checked[1000005];
int fat[1000005];
int tmp[1000005];
void dfs(int pos,int fa){
    fat[pos]=fa;
    for(int to:ro[pos]){
        if(fa==to) continue;
        dfs(to,pos);
    }
}
int main(){
    n=read();
    for(int i = 1,x,y;i<n;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
    }
    dfs(1,0);
    q=read();
    for(int i = 1,idx;i<=q;i++){
        idx=read();
        long long ans=0;
        for(int j = 1,k;j<=idx;j++){
            k=read();
            tmp[j]=k;
            checked[k]=true;
        }
        for(int j = 1;j<=idx;j++){
            if(checked[fat[tmp[j]]])ans+=1;
        }
        for(int j = 1;j<=idx;j++){
            checked[tmp[j]]=false;
        }
        printf("%lld\n",ans);;
    }
}