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
int n,m,idx,root[1000005];
struct node{
    int lc;
    int rc;
    int val;
}tr[1000001*30];
void build(int &pos,int l,int r){
    pos=++idx;
    if(l==r){
        return tr[pos].val=read(),void();
    }
    int mid = (l+r)>>1;
    build(tr[pos].lc,l,mid);
    build(tr[pos].rc,mid+1,r);
}
void update(int pre,int &pos,int l,int r,int x,int val){
    pos=++idx;tr[pos]=tr[pre];
    if(l==r){
        return tr[pos].val=val,void();
    }
    int mid = (l+r)>>1;
    if(mid>=x)update(tr[pre].lc,tr[pos].lc,l,mid,x,val);
    else update(tr[pre].rc,tr[pos].rc,mid+1,r,x,val);
}
int query(int pos,int l,int r,int x){
    if(l==r){
        return tr[pos].val;
    }
    int mid = (l+r)>>1;
    if(mid>=x)return query(tr[pos].lc,l,mid,x);
    else return query(tr[pos].rc,mid+1,r,x);
}
int main(){
    n=read(),m=read();
    build(root[0],1,n);
    for(int i = 1,ver,loc,val,opt;i<=m;i++){
        ver=read(),opt=read(),loc=read();
        if(opt&1){
            val=read();
            update(root[ver],root[i],1,n,loc,val);
        }else{
            cout<<query(root[ver],1,n,loc)<<endl;
            root[i]=root[ver];
        }
    }
    return 0;
}