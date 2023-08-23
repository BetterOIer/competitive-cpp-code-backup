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
struct query{
    int opt;
    int k;
    int t,temp,power;
}req[2000005];
int n,tr[2][2000005],SUM;
int temp[2000005],tot;
int lowbit(int x){
    return x&(-x);
}
void add(int pos,int y,int whi){
    for(int i = pos;i<=tot;i+=lowbit(i)){
        tr[whi][i]+=y;
    }
}
int query(int x,int whi){
    int ans=0;
    for(int i = x;i;i-=lowbit(i)){
        ans+=tr[whi][i];
    }
    return ans;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        req[i].opt=read();
        if(req[i].opt&1){
            req[i].t=read(),req[i].temp=read(),req[i].power=read();
            temp[++tot]=req[i].temp;
        }else req[i].k=read();
    }
    sort(temp+1,temp+tot+1);
    tot=unique(temp+1,temp+tot+1)-temp-1;
    for(int i = 1;i<=n;i++){
        if(req[i].opt&1){
            req[i].temp=lower_bound(temp+1,temp+tot+1,req[i].temp)-temp;
        }
    }
    for(int i = 1;i<=n;i++){
        if(req[i].opt&1) add(req[i].temp+req[i].t,req[i].power,req[i].t),SUM+=req[i].t*req[i].power;
        else{
            int whi = req[i].k;
            add(req[whi].temp+req[whi].t,-req[whi].power,req[whi].t),SUM-=req[whi].t*req[whi].power;
        }
        int sum0=0,sum1=SUM,f0=0,pos0=0;
        for(int i = 20;i>=0;i--){
            int now_pos = pos0+(1<<i),now_sum0 = sum0+tr[0][now_pos],now_sum1=sum1-tr[1][now_pos];
            if(now_pos>tot)continue;
            if(now_sum0<now_sum1){
                pos0 = now_pos;
                sum0 = now_sum0,sum1 = now_sum1;
            }
        }
        f0=sum0,sum0=0,sum1 = SUM;
        int f1=0,pos1=0;
        if (pos0 < tot){
            f1 = min(query(pos0+1,0),SUM-query(pos0+1,1));
            for(int i = 20;i>=0;i--){
                int now_pos = pos1 + (1 << i),now_sum0 = sum0+tr[0][now_pos],now_sum1=sum1-tr[1][now_pos];
                if(now_pos>tot)continue;
                if(now_sum0<now_sum1){
                    pos1 = now_pos;
                    sum0 = now_sum0,sum1 = now_sum1;
                }else if(min(now_sum0, now_sum1) == f1){
                    pos1 = now_pos;
                    sum0 = now_sum0,sum1 = now_sum1;
                }
            }
        }
        if(!(f0|f1))cout<<"Peace\n";
        else if(f0>f1)cout<<temp[pos0]<<" "<<(f0<<1)<<endl;
        else cout<<temp[pos1]<<" "<<(f1<<1)<<endl;
    }
    return 0;
}