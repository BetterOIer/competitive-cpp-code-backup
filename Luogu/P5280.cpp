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
const int mod = 998244353;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    int val;
    int f;
    int tf;
    int g;
    int tg;
}tr[2000005];
int n,m,k=1;
void pushup(int pos){
    tr[pos].val = ((tr[pos].f+tr[pos<<1].val)%mod+tr[pos<<1|1].val)%mod;
}
void pushtag_f(int pos,int val){
    tr[pos].val = 1LL* tr[pos].val*val%mod;
    tr[pos].tf = 1LL* tr[pos].tf*val%mod;
    tr[pos].f = 1LL* tr[pos].f*val%mod;
}
void pushtag_g(int pos,int val){
    tr[pos].g = 1ll*tr[pos].g*val%mod;
    tr[pos].tg = 1ll*tr[pos].tg*val%mod;
}
void pushdown(int pos){
    if(tr[pos].tf!=1){
        pushtag_f(pos<<1,tr[pos].tf);
        pushtag_f(pos<<1|1,tr[pos].tf);
        tr[pos].tf = 1;
    }
    if(tr[pos].tg!=1){
        pushtag_g(pos<<1,tr[pos].tg);
        pushtag_g(pos<<1|1,tr[pos].tg);
        tr[pos].tg = 1;
    }
}
void build(int pos,int l,int r){
    tr[pos].g=tr[pos].tf=tr[pos].tg=1;
    if(l==r)return;
    int mid = (l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
}
void update(int pos,int l, int r, int x, int y){
    pushdown(pos);
    if(l==x&&r==y){
        (tr[pos].f+=k)%=mod;
        pushtag_f(pos<<1,2);
        pushtag_f(pos<<1|1,2);
    }else{
        int mid = (l+r)>>1;
        (tr[pos].g+=k)%=mod;
        if(y<=mid){
            update(pos<<1,l,mid,x,y);
            pushdown(pos<<1|1);
            (tr[pos<<1|1].f+=((k-tr[pos<<1|1].g)%mod+mod)%mod)%=mod;
            (tr[pos<<1|1].g+=tr[pos<<1|1].g)%=mod;
            pushtag_f((pos<<1|1)<<1,2);
            pushtag_f((pos<<1|1)<<1|1,2);
            pushtag_g((pos<<1|1)<<1,2);
            pushtag_g((pos<<1|1)<<1|1,2);
            pushup(pos<<1|1);
        }else if(x>mid){
            update(pos<<1|1,mid+1,r,x,y);
            pushdown(pos<<1);
            (tr[pos<<1].f+=((k-tr[pos<<1].g)%mod+mod)%mod)%=mod;
            (tr[pos<<1].g+=tr[pos<<1].g)%=mod;
            pushtag_f((pos<<1)<<1,2);
            pushtag_f((pos<<1)<<1|1,2);
            pushtag_g((pos<<1)<<1,2);
            pushtag_g((pos<<1)<<1|1,2);
            pushup(pos<<1);
        }else{
            update(pos<<1,l,mid,x,mid);
            update(pos<<1|1,mid+1,r,mid+1,y);
        }
    }
    pushup(pos);
}
int main(){
    n=read(),m=read();
    build(1,1,n);
    for(int opt,l,r,i=1;i<=m;i++){
        if(opt&1){
            l=read(),r=read();
            update(1,1,n,l,r);
            (k+=k)%=mod;
        }else{
            cout<<tr[1].val<<endl;
        }
    }
    return 0;
}

//TODO:DEBUG!!!