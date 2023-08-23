/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/




















/* 






#include<iostream>
#include<vector>
using namespace std;
vector <int> tr[500005];
int depth[500001], fa[500001][22], lg[500001];
int n,q,root;
int ans[500001],__;
#define ui unsigned int
ui s;

inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void dfs(int now, int fath) {
	fa[now][0] = fath; depth[now] = depth[fath] + 1;
	for(int i = 1; i <= lg[depth[now]]; ++i)
		fa[now][i] = fa[fa[now][i-1]][i-1];
    for(int i = 0;i<=tr[now].size()-1;i++){
        if(tr[now][i]!=fath) dfs(tr[now][i],now);
    }
}
int ask(int x,int k){
    for(;depth[x]>k;){
        x = fa[x][lg[depth[x]-k] - 1];
    }
    return x;
}

int main(){
    n=read(),q=read(),s=read();
    for(int i = 1,fat;i<=n;i++){
        fat=read();
        if(!fat){root=i;continue;}
        fa[i][0]=fat;
        tr[fat].push_back(i);
        tr[i].push_back(fat);
    }
    for(int i = 1;i<=n;i++)lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    dfs(root,0);
    for(int i = 1,x,k;i<=q;i++){
        x=(get(s)^ans[__])%n+1,k=(get(s)^ans[__])%depth[i];
        ans[++__]=ask(x,depth[x]-k);
    }
    int ANS=0;
    for(int i = 1;i<=n;i++){
        ANS^=(i*ans[i]);
    }
    cout<<ANS;
    return 0;
} */










#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x;
}
#define ui unsigned int
ui s;
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}
int n,q;
int fa[23][500005],st,d[500005];
bool pd[500005];
ll ans,Ans;
int dfs(int x){
    if(!x)return 0;
    if(d[x])return d[x];
    return d[x]=dfs(fa[0][x])+1;
}
int main(){
    n=read(),q=read(),s=read();
    for(int i=1;i<=n;i++)fa[0][i]=read(),st=(fa[0][i]==0)?i:st,pd[fa[0][i]]=1;
    for(int k=1;k<=__lg(n);k++)
        for(int i=1;i<=n;i++)
            fa[k][i]=fa[k-1][fa[k-1][i]];
    for(int i=1;i<=n;i++){
        if(!pd[i])dfs(i);
    }
    for(int i=1;i<=q;i++){
        int x=((get(s)^ans)%n)+1,w=(get(s)^ans)%d[x];
        for(int k=__lg(w);~k;--k){
            if(w>=(1<<k))x=fa[k][x],w-=(1<<k);
        }
        ans=x;
        Ans^=ans*i;
    }
    cout<<Ans;
}


