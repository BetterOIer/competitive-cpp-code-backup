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
struct node{
    int sum;
    int max_m;
    int max_l;
    int max_r;
}tr[2000005];
void pushup(int pos){
    tr[pos].sum=tr[pos<<1].sum+tr[pos<<1|1].sum;
    tr[pos].max_l=max(tr[pos<<1].max_l,tr[pos<<1].sum+tr[pos<<1|1].max_l);
    tr[pos].max_m=max(max(tr[pos<<1].max_m,tr[pos<<1|1].max_m),tr[pos<<1].max_r+tr[pos<<1|1].max_l);
    tr[pos].max_r=max(tr[pos<<1|1].max_r,tr[pos<<1|1].sum+tr[pos<<1].max_r);
}
void build(int pos,int l,int r){
    if(l==r){
        tr[pos].sum=tr[pos].max_l=tr[pos].max_m=tr[pos].max_r=read();
        return;
    }
    int mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushup(pos);
}
node query(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return tr[pos];
    }
    int mid = (l+r)>>1;
    if(mid>=y)return query(pos<<1,l,mid,x,y);
    else if(mid<x)return query(pos<<1|1,mid+1,r,x,y);
    else{
        node ans,ans1=query(pos<<1,l,mid,x,y),ans2=query(pos<<1|1,mid+1,r,x,y);
        ans.max_l=max(ans1.max_l,ans1.sum+ans2.max_l);
        ans.max_m=max(max(ans1.max_m,ans2.max_m),ans1.max_r+ans2.max_l);
        ans.max_r=max(ans2.max_r,ans2.sum+ans1.max_r);
        return ans;
    }
}
void update(int pos,int l,int r,int x,int val){
    if(l==r){
        tr[pos].sum=tr[pos].max_l=tr[pos].max_m=tr[pos].max_r=val;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=x)update(pos<<1,l,mid,x,val);
    else update(pos<<1|1,mid+1,r,x,val);
    pushup(pos);
}
int main(){
    n=read(),m=read();
    build(1,1,n);
    for(int i = 1,opt,x,y;i<=m;i++){
        opt=read(),x=read(),y=read();
        if(opt&1){
            if(x>y)swap(x,y);
            cout<<query(1,1,n,x,y).max_m<<endl;
        }else{
            update(1,1,n,x,y);
        }
    }
    return 0;
}