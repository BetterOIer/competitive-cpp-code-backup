/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,root,idx=0;
long long a[200005];
struct node{
    int ch[2];
    int l_lim,r_lim;
}tr[200005*20];
void insert(int &pos,int dep,long long val,int id){
    if(!pos)pos=++idx;
    if(!tr[pos].l_lim)tr[pos].l_lim=id;
    tr[pos].r_lim=id;
    if(dep==-1)return;
    int c = (val>>dep)&1;
    insert(tr[pos].ch[c],dep-1,val,id);
}
long long query(int pos,int dep,long long val){
    if(dep==-1)return 0;
    int c = (val>>dep)&1;
    if(tr[pos].ch[c])return query(tr[pos].ch[c],dep-1,val);
    else return query(tr[pos].ch[c^1],dep-1,val)+(1<<dep);
}
long long dfs(int pos,long long dep){
    if(dep==-1)return 0;
    if(tr[pos].ch[0]&&tr[pos].ch[1]){
        long long res= 9223372036854775807ll;
        for(int i = tr[tr[pos].ch[0]].l_lim;i<=tr[tr[pos].ch[0]].r_lim;i++){
            res=min(res,query(tr[pos].ch[1],dep-1,a[i])+1LL*(1<<dep));
        }
        return dfs(tr[pos].ch[0],dep-1)+dfs(tr[pos].ch[1],dep-1)+res;
    }else if(tr[pos].ch[0]) return dfs(tr[pos].ch[0],dep-1);
    else return dfs(tr[pos].ch[1],dep-1);
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i =1;i<=n;i++) insert(root,31,a[i],i);
    cout<<dfs(root,31);
    return 0;
}