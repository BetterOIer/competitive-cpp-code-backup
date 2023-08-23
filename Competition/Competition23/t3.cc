#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
struct node{
    int from;
    int to;
    int val;
    int bel;
};/* 
set<pair<int,int>> S; */
node ro[200005];
deque<int>Q[2];
int cnt=0,n,m,k;
long long minti=9223372036854775807ll;
void check(){
    
}
void dfs(int now,int whi){
    if(now==n){
        if(Q[1].size()==k&&Q[2].size()==n-1-k){
            check();
            return ;
        }
    }
    for(int i = whi;i<=n-1-now;i++){
        Q[ro[i].bel+1].push_back(i);
        dfs(now+1,i+1);
        Q[ro[i].bel+1].pop_back();
    }
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i = 1;i<=m;i++){
        ro[++cnt].from=read();
        ro[cnt].to=read();
        ro[cnt].val=read();
        ro[cnt].bel=read();
    }
    S.clear();
    dfs(1,1);
    //fclose(stdin);
    //fclose(stdout);
}