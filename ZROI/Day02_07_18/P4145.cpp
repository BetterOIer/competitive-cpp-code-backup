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
struct seg{
    long long maxx;
    long long val;
}tr[400005];
long long n,q;
void pushup(long long pos){
    tr[pos].val=tr[pos<<1].val+tr[pos<<1|1].val;
    tr[pos].maxx=max(tr[pos<<1].maxx,tr[pos<<1|1].maxx);
}
void build(long long pos,long long l,long long r){
    if(l==r){
        tr[pos].maxx=tr[pos].val=read();
        return;
    }
    long long mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushup(pos);
}
long long query(long long pos,long long l,long long r,long long x,long long y){
    if(x<=l&&r<=y){
        return tr[pos].val;
    }
    long long mid = (l+r)>>1,ans=0;
    if(x<=mid)ans+=query(pos<<1,l,mid,x,y);
    if(y>mid)ans+=query(pos<<1|1,mid+1,r,x,y);
    return ans;
}
void update(long long pos,long long l,long long r,long long x,long long y){
    if(tr[pos].maxx==1)return;
    if(l==r){
         tr[pos].maxx=tr[pos].val=__builtin_sqrt(tr[pos].val);
         return;
    }
    long long mid = (l+r)>>1;
    if(x<=mid)update(pos<<1,l,mid,x,y);
    if(y>mid)update(pos<<1|1,mid+1,r,x,y);
    pushup(pos);
}
int main(){
    n=read();
    build(1,1,n);
    q=read();
    for(long long i = 1,opt,x,y;i<=q;i++){
        opt=read(),x=read(),y=read();
        if(x>y)swap(x,y);
        if(opt&1){
            printf("%lld\n",query(1,1,n,x,y));
        }else{
            update(1,1,n,x,y);
        }
    }
    return 0;
}