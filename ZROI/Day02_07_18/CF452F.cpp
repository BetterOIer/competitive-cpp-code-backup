/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
const long long mod = 1e9+7;
const long long BASE = 3;
long long n,a[1600005],f[1600005]={1};
struct node{
    long long len;
    long long h1;
    long long h2;
}tr[1600005];
node operator + (node a,node b){
    node ans;
    ans.len=a.len+b.len;
    ans.h1=((a.h1*f[b.len])%mod+b.h1)%mod;
    ans.h2=((b.h2*f[a.len])%mod+a.h2)%mod;
    return ans;
}
void build(long long pos,long long l,long long r){
    tr[pos].len=r-l+1,tr[pos].h1=tr[pos].h2=0;
    if(l==r) return;
    long long mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
}
void update(long long pos,long long l,long long r,long long x,long long val=1){
    if(l==r){
        tr[pos].h1=tr[pos].h2=val;
        return;
    }
    long long mid = (l+r)>>1;
    if(mid>=x)update(pos<<1,l,mid,x,val);
    else update(pos<<1|1,mid+1,r,x,val);
    tr[pos]=tr[pos<<1]+tr[pos<<1|1];
}
node query(long long pos,long long l,long long r,long long x,long long y){
    //cout<<pos<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
    if(x<=l&&r<=y){
        return tr[pos];
    }
    long long mid = (l+r)>>1;
    if(mid>=y)return query(pos<<1,l,mid,x,y);
    if(mid<x)return query(pos<<1|1,mid+1,r,x,y);
    return query(pos<<1,l,mid,x,y)+query(pos<<1|1,mid+1,r,x,y);
}
int main(){
    for(long long i = 1;i<=1600000;i++)f[i]=f[i-1]*BASE%mod;
    int t=read();
    while(t--){
        n=read();
        build(1,1,n);
        for(long long i = 1;i<=n;i++){
            a[i]=read();
        }
        for(long long i = 1;i<=n;i++){
            update(1,1,n,a[i]);
            long long x=min(a[i]-1,n-a[i]);
            if(x<1)continue;
            if(query(1,1,n,a[i]-x,a[i]-1).h1!=query(1,1,n,a[i]+1,a[i]+x).h2/* &&i>=3 */){
                puts("Y");
                goto en;
            }
        }
        puts("N");
        en:
        for(int i = 1;i<=n;i++)a[i]=0;
        for(int i = 0;i<=1600004;i++)tr[i].h1=tr[i].h2=tr[i].len=0;
    }
    return 0;
}