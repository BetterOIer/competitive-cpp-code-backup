/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    int lc;
    int rc;
    int val;
}tr[40000005];
int root[200005],val[200005];
int idx=0,n,m,maxn;
vector<int>a;
void build(int &pos,int l,int r){
    pos=++idx;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(tr[pos].lc,l,mid);build(tr[pos].rc,mid+1,r);
}
void insert(int pre,int &pos,int l,int r,int val){
    pos=++idx;tr[pos]=tr[pre];tr[pos].val++;
    if(l==r)return;
    int mid = (l+r)>>1;
    if(mid>=val)insert(tr[pre].lc,tr[pos].lc,l,mid,val);
    else insert(tr[pre].rc,tr[pos].rc,mid+1,r,val);
}
int query(int l_pos,int r_pos,int l,int r,int rank){
    if(l==r)return l;
    int mid = (l+r)>>1;
    int s = tr[tr[r_pos].lc].val-tr[tr[l_pos].lc].val;
    if(s>=rank) return query(tr[l_pos].lc,tr[r_pos].lc,l,mid,rank);
    else return query(tr[l_pos].rc,tr[r_pos].rc,mid+1,r,rank-s);
}
int getid(int val){
    return lower_bound(a.begin(),a.end(),val)-a.begin()+1;
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        val[i]=read();
        a.push_back(val[i]);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    maxn=a.size();
    build(root[0],1,maxn);
    for(int i = 1;i<=n;i++){
        insert(root[i-1],root[i],1,maxn,getid(val[i]));
    }
    for(int i = 1,x,y,z;i<=n;i++){
        x=read(),y=read(),z=read();
        cout<<a[query(root[x-1],root[y],1,maxn,z)-1]<<endl;
    }
    return 0;
}