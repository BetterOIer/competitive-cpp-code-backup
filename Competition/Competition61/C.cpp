/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: http://betteroier.site:1000
* FileStation: http://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
/* #include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}

int main(){
    
    return 0;
}
 */

/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
/*#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int dep[5000005],fa[5000005][22];
vector<int>ro[5000005];
void dfs(int now,int fat){
    dep[now]=dep[fat]+1;
    fa[now][0]=fat;
    for(int i = 1;i<=19;i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
    }
    for(int to:ro[now]){
        if(to==fat)continue;
        dfs(to,now);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i = 19;i>=0;i--){
        if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    }
    if(u==v)return v;
    for(int i = 19;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i],v=fa[v][i];
        }
    }
    return fa[u][0];
}
int*/
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 5;
int n, dn[2], dfn[2][N], mi[2][19][N],fa[2][N];
vector<int> e[2][N];
set<int>s[3];
int get(int x, int y) {return dfn[x] < dfn[y] ? x : y;}
void dfs(int whi,int id, int f) {
    fa[whi][id]=f;
    mi[whi][0][dfn[whi][id] = ++dn[whi]] = f;
    for(int it : e[whi][id]) if(it != f) dfs(whi, it, id); 
}
int lca(int whi, int u, int v) {
    if(u == v) return u;
    if((u = dfn[whi][u]) > (v = dfn[whi][v])) swap(u, v);
    int d = __lg(v - u++);
    return get(mi[whi][d][u], mi[whi][d][v - (1 << d) + 1]);
}
void find(int whi, int pos, int last){
    if(s[whi].find(pos)==s[whi].end()){s[whi].insert(pos);cout<<pos<<" ";}
    if(last==pos)return;
    pos=fa[whi][pos];
    find(whi,pos,last);
}
int get(){
    for(set<int>::iterator i=s[0].begin();i!=s[0].end();i++){
        for(set<int>::iterator j=i;j!=s[0].end();j++){
            int lcaa=lca(1,*i,*j);
            find(1,*i,lcaa);find(1,*j,lcaa);
        }
    }
    int size=s[1].size();cout<<"in s1: "<<size<<endl<<endl;
    s[0].clear();
    s[1].clear();
    return size;
}
void getnum(int x){
    int cnt=1;
    while(x){
        if(x&1)s[2].insert(cnt);
        cnt++;
        x>>=1;
    }
    for(set<int>::iterator i=s[2].begin();i!=s[2].end();i++){
        cout<<*i<<" ";
    }
    cout<<"in s2: "<<s[2].size()<<endl;
}
int main() {
    scanf("%d", &n);
    for(int i = 2, u; i <= n; i++) {
        scanf("%d", &u);
        e[0][u].push_back(i), e[0][i].push_back(u);
    }
    for(int i = 2, u; i <= n; i++) {
        scanf("%d", &u);
        e[1][u].push_back(i), e[1][i].push_back(u);
    }
    dfs(0, 1, 0);
    dfs(1, 1, 0);
    for(int i = 1; i <= __lg(n); i++)
    for(int j = 1; j + (1 << i) - 1 <= n; j++)
        mi[0][i][j] = get(mi[0][i - 1][j], mi[0][i - 1][j + (1 << i - 1)]);
    for(int i = 1; i <= __lg(n); i++)
        for(int j = 1; j + (1 << i) - 1 <= n; j++)
            mi[1][i][j] = get(mi[1][i - 1][j], mi[1][i - 1][j + (1 << i - 1)]);

    //for(int i = 1, u, v; i <= m; i++) scanf("%d %d", &u, &v), printf("%d\n", lca(u, v));
    long long ans=0;
    for(int _ = 1;_<=(1<<n)-1;_++){
        getnum(_);
        for(set<int>::iterator i=s[2].begin();i!=s[2].end();i++){
            for(set<int>::iterator j=i;j!=s[2].end();j++){
                if(*i==*j)continue;
                int lcaa=lca(0,*i,*j);
                find(0,*i,lcaa);find(0,*j,lcaa);
                cout<<"in s0: "<<s[0].size()<<endl;
                ans+=get();
            }
        }
        s[2].clear();
    }
    /* for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            int lcaa=lca(0,i,j);
            find(0,i,lcaa);find(0,j,lcaa);
            cout<<"in s0: "<<s[0].size()<<endl;
            ans+=get();
        }
    } */
    
    cout<<ans;
    return 0;
}