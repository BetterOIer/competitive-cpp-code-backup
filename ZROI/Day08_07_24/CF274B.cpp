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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
struct node{
    long long val,up,down;
    vector<long long> son;
}tr[100004];
void dfs(long long pos,long long fa){
    for(long long to:tr[pos].son){
        if(to==fa)continue;
        dfs(to,pos);
        tr[pos].up=max(tr[pos].up,tr[to].up);
        tr[pos].down=max(tr[pos].down,tr[to].down);
    }
    tr[pos].val+=tr[pos].up-tr[pos].down;
    if(tr[pos].val>0)tr[pos].down+=tr[pos].val;
    else tr[pos].up-=tr[pos].val;
}
int main(){
    n=read();
    for(long long i = 1,x,y;i<n;i++){
        x=read(),y=read();
        tr[x].son.push_back(y);
        tr[y].son.push_back(x);
    }
    for(long long i = 1;i<=n;i++){
        tr[i].val=read();
        if(tr[i].val>0)tr[i].down=tr[i].val;
        else tr[i].up=-tr[i].val;
    }
    dfs(1,0);
    printf("%lld\n",tr[1].down+tr[1].up);
    return 0;
}