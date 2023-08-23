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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int ans[7007];
struct STA{
    int pla;
    int v;
    int idx;
}stats[7007];
int pm[7007],rk[7007],pl[7007],rkv[7007],pmv[7007];
struct REQ{
    int tim;
    int k;
    int idx;
}req[7007];
bool operator < (const REQ a,const REQ b){
    return a.tim<b.tim;
}
bool cmp3(const STA a,const STA b){
    return a.idx<b.idx;
}
bool cmp2(const STA a,const STA b){
    if(a.pla==b.pla)return a.idx>b.idx;
    return a.pla>b.pla;
}
bool cmp1(const STA a,const STA b){
    return a.v<b.v;
}
struct node{
    int val;
};
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        stats[i].v=read();
        stats[i].pla=read();
        stats[i].idx=i;
    }
    sort(stats+1,stats+n+1,cmp1);
    for(int i = 1;i<=n;i++){
        rkv[i]=stats[i].idx;
        pmv[stats[i].idx]=i;
    }
    sort(stats+1,stats+n+1,cmp2);
    for(int i = 1;i<=n;i++){
        pm[stats[i].idx]=i;
        rk[i]=stats[i].idx;
        pl[stats[i].idx]=stats[i].pla;
    }
    sort(stats+1,stats+n+1,cmp3);
    m=read();
    for(int i = 1;i<=m;i++){
        req[i].tim=read(),req[i].k=read(),req[i].idx=i;
    }
    sort(req+1,req+m+1);


    int TIM=0;
    for(int i = 1;i<=m;i++){
        if(TIM<req[i].tim){for(int j = 1;j<=n;j++){
            for(int k = 1;k<pmv[j];k++){
                if(pl[j]<=pl[rkv[k]]&&stats[j].v-stats[rkv[k]].v>0){
                    if((pl[rkv[k]]-pl[j])<(stats[j].v-stats[rkv[k]].v)*(req[i].tim-TIM)){
                        pm[j]--,pm[rkv[k]]++;
                    }else if((pl[rkv[k]]-pl[j])==(stats[j].v-stats[rkv[k]].v)*(req[i].tim-TIM)){
                        if(stats[j].idx<=stats[rkv[k]].idx)pm[j]--,pm[rkv[k]]++;
                    }
                }
            }
        }
        for(int j = 1;j<=n;j++){
            pl[j]+=stats[j].v*(req[i].tim-TIM);
            rk[pm[j]]=j;
        }
        TIM=req[i].tim;}
        ans[req[i].idx]=rk[req[i].k];
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}