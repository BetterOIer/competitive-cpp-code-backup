/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,ANSS=2147283647,MAXN=0,MINN=2147483647;
bool chosen[100005];
int li[100005];
void dfs(int pos, int step){
    /* cout<<step<<' ';
    for(int i = 1;i<=n;i++){
        cout<<chosen[i];
    }
     */
    if(step==m){
        ANSS=min(ANSS,MAXN-MINN);
        //cout<<" "<<ANSS<<endl;
        return;
    }
    //cout<<endl;
    for(int i = pos;i<=n;i++){
        if(chosen[i]||chosen[i-1]||chosen[i+1])continue;
        chosen[i]=true;
        int tmp_ma=MAXN,tmp_mn=MINN;
        MAXN=max(MAXN,li[i]);
        MINN=min(MINN,li[i]);
        dfs(i,step+1);
        MAXN=tmp_ma;
        MAXN=tmp_mn;
        chosen[i]=false;
    }
}
int main(){
    n=read(),m=read();
    bool flag=true;
    int maxn=0,minn=2147483647;
    int maxn2=0,minn2=2147483647;
    for(int i = 1;i<=n;i++){
        li[i]=read();
        if(li[i]<li[i-1])flag=false;
        if(i&1)maxn=max(maxn,li[i]);
        if(i&1)minn=min(minn,li[i]);
        if((i&1)==0)maxn2=max(maxn2,li[i]);
        if((i&1)==0)minn2=min(minn2,li[i]);
    }
    //4pts;
    if(ceil(1.0*n/2)==m){
        if(m*2==n){
            int ans=min(maxn-minn,maxn2-minn2);
            cout<<ans<<endl;
        }
        else{int ans=maxn-minn;
        cout<<ans<<endl;}
        return 0;
    }
    //12pts
    if(flag){
        int minn = 2147483647;
        for(int i = 1;i<=n-((m<<1)-1)+1;i++){
            minn=min(minn,li[i+(m<<1)-2]-li[i]);
        }
        cout<<minn<<endl;
        return 0;
    }
    //48pts
    dfs(1,0);
    cout<<ANSS<<endl;
    return 0;
}