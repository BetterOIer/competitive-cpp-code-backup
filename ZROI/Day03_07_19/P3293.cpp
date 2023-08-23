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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int a[200005],maxn=0,idx=0,root[200005];
struct node{
    int val;
    int lc;
    int rc;
}tr[200005*20+5];
void build(int &pos,int l,int r){
    pos=++idx;
    if(l==r)return;
    int mid = (l+r)>>1;
    build(tr[pos].lc,l,mid);build(tr[pos].rc,mid+1,r);
}
void insert(int pre,int &pos,int l,int r,int x,int val=1){
    pos=++idx;tr[pos]=tr[pre];tr[pos].val++;
    if(l==r) return;
    int mid = (l+r)>>1;
    if(mid>=x)insert(tr[pre].lc,tr[pos].lc,l,mid,x,val);
    else insert(tr[pre].rc,tr[pos].rc,mid+1,r,x,val);
}
int query(int pre,int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tr[pos].val-tr[pre].val;
    if(y<l||x>r) return 0;
    int mid = (l+r)>>1,ans=0;
    if(mid>=x)ans+=query(tr[pre].lc,tr[pos].lc,l,mid,x,y);
    if(mid<y)ans+=query(tr[pre].rc,tr[pos].rc,mid+1,r,x,y);
    return ans;
}
int main(){
    n=read(),m=read();
    for(int i =1;i<=n;i++){
        a[i]=read(),maxn=max(maxn,a[i]);
    }
    build(root[0],0,maxn);
    for(int i = 1;i<=n;i++){
        insert(root[i-1],root[i],0,maxn,a[i]);
    }
    for(int i = 1,b,x,l,r,ans=0;i<=m;i++){
        b=read(),x=read(),l=read(),r=read(),ans=0;
        for(int len = 17;len>=0;len--){
            int c = b>>len&1;
            if(c&&!query(root[l-1],root[r],0,maxn,ans-x,ans-x+(1<<len)-1))ans+=(1<<len);
            if((!c)&&query(root[l-1],root[r],0,maxn,ans-x+(1<<len),ans-x+(1<<(len+1))-1))ans+=(1<<len);
        }
        cout<<(ans^b)<<endl;
    }
    return 0;
}