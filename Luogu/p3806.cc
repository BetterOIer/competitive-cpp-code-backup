#include<iostream>
#include <vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,q[105],d[10000],hav[10000005],cnt=0;
int ans[105];
struct ro{
    int to;
    int val;
};
struct node{
    vector <ro> to;
    int size;
    int dis;
    int mx;
    bool usd;

}tree[100005];
int root;
void getroot(int now,int fa){
    tree[now].size=1,tree[now].mx=0;
    for(int i=0;i<=tree[now].to.size()-1;i++){
        if(tree[now].to[i].to==fa || tree[tree[now].to[i].to].usd) continue;
        getroot(tree[now].to[i].to,now);
        tree[now].size+=tree[tree[now].to[i].to].size;
        tree[now].mx=max(tree[now].mx,tree[tree[now].to[i].to].size);
    }
    tree[now].mx=max(tree[now].mx,tree[0].mx-tree[now].size);
    if(tree[now].mx<tree[root].mx) root=now;
}

void getdis(int now,int fa){
    d[++cnt]=tree[now].dis;
    for(int i = 0;i<=tree[now].to.size()-1;i++){
        if(tree[now].to[i].to==fa||tree[tree[now].to[i].to].usd) continue;
        tree[tree[now].to[i].to].dis=tree[now].dis+tree[now].to[i].val;
        getdis(tree[now].to[i].to,now);
    }
}

void calc(int now){
    hav[0]=1;
    vector<int>v;
    for(int i = 0;i<=tree[now].to.size()-1;i++){
        if(tree[tree[now].to[i].to].usd)continue;
        cnt=0;
        tree[tree[now].to[i].to].dis=tree[now].to[i].val;
        getdis(tree[now].to[i].to,now);
        
		
        for(int j = 1;j<=cnt;j++){
            for(int k = 1;k<=m;k++){
                if(q[k]>=d[j]) ans[k] |= hav[ q[k] - d[j] ];
            }
        }
        for(int j = 1;j<=cnt;j++){
            if(d[j]<=1e7){
                hav[d[j]] =1;
                v.push_back(d[j]);
            }
        }
    }
    //for(auto i:v){
    for(int i=0;i<v.size();i++){
        hav[v[i]]=0;
    }
}
void divid(int now){
    calc(now);
    tree[now].usd=true;
    for(int i = 0;i<=tree[now].to.size()-1;i++){
        if(!tree[tree[now].to[i].to].usd){
            root=0;
            tree[0].mx=tree[tree[now].to[i].to].size;
            getroot(tree[now].to[i].to,0),getroot(root,0);
            divid(root);
        }
    }
}
int main(){
    n=read(),m=read();
    int u,v,w;
    for(int i = 1;i<n;i++){
        u=read(),v=read(),w=read();
        tree[u].to.push_back((ro){v,w});
        tree[v].to.push_back((ro){u,w});
    }
    for(int i = 1;i<=m;i++){
        cin>>q[i];
    }
    tree[0].mx=n;
    getroot(1,0),getroot(root,0);
    divid(root);
    for(int i = 1;i<=m;i++){
        puts(ans[i]? "AYE":"NAY");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
