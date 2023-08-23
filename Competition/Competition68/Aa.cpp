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
#include<map>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,maxn,maxnum=0;
int a[15];
map<int,int>m;
vector<int>ro[15];
int ans=0,win=0;
void dfs(int pos,int step,int av,int bv){
    if(step&1){
        av+=a[pos];
    }else{
        bv+=a[pos];
    }
    if(ro[pos].empty()){
        if(step&1){
            if(ans<=av-bv){
                ans=av-bv;
                win=1;
            }
        }else{
            if(ans<=bv-av){
                ans=bv-av;
                win=2;
            }
        }
        return;
    }
    for(int i:ro[pos]){
        dfs(i,step+1,av,bv);
    }
}
int main(){
     n=read(),maxn=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();maxnum=max(maxnum,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i = n;i>=1;i--){
        m[a[i]]=i;
    }
    for(int i = 0;i<=n;i++){
        auto _ = upper_bound(a+1,a+n+1,min(a[i]+maxn,maxnum));_--;
        /* if(>=){
            ro[i].push_back(m[*_]);
        } */
        for(int j = m[*_];j>=i+1;j--){
            ro[i].push_back(j);
        }
    }
    dfs(0,0,0,0);
    cout<<((win&1? 1:-1)*ans)<<endl;
    return 0;
}