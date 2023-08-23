/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
const long long max_bit=63;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m;
struct node{
    long long to;
    long long val;
};
vector<node>ro[50005];
long long a[66];
void insert(long long val){
    for(long long i = max_bit;~i;i--){
        if(val&(1ll<<i)){
            if(!a[i])return a[i]=val,void();
            val^=a[i];
        }
    }
}
long long qmax(long long x){
    long long ans=x;
    for(long long i = max_bit;~i;i--){
        ans=max(ans,ans^a[i]);
    }
    return ans;
}
long long ans[50005];
bool vis[50005];
void dfs(long long pos,long long res){
    vis[pos]=true,ans[pos]=res;
    for(node to:ro[pos]){
        if(vis[to.to]) insert(res^to.val^ans[to.to]);
        else dfs(to.to,res^to.val);
    }
}
int main(){
    n=read(),m=read();
    for(long long i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
        ro[v].push_back((node){u,w});
    }
    dfs(1,0);
    cout<<qmax(ans[n])<<endl;
    return 0;
}
