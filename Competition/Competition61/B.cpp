/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: http://betteroier.site:1000
* FileStation: http://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,x_idx,y_idx;
struct node{
    long long x;
    long long y;
    long long val;
}po[2500005];
bool cmp1(node a,node b){
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
bool cmp2(node a,node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
map<long long, long long>X,Y;
long long a[2500005],poi=1;
/*long long dp[2500005];
long long dps(){
	dp[1]=a[1];
	for(long long i=1;i<=n;i++)
	{
		dp[i]=max(a[i],dp[i-1]+a[i]);
	}
	long long m=dp[1];
	for(long long i=1;i<=n;i++)
	{
		m=max(m,dp[i]);
	}
	return m;
}
 */


struct Node{
    long long sum;
    long long max_m;
    long long max_l;
    long long max_r;
}tr[8000005];
void pushup(long long pos){
    tr[pos].sum=tr[pos<<1].sum+tr[pos<<1|1].sum;
    tr[pos].max_l=max(tr[pos<<1].max_l,tr[pos<<1].sum+tr[pos<<1|1].max_l);
    tr[pos].max_m=max(max(tr[pos<<1].max_m,tr[pos<<1|1].max_m),tr[pos<<1].max_r+tr[pos<<1|1].max_l);
    tr[pos].max_r=max(tr[pos<<1|1].max_r,tr[pos<<1|1].sum+tr[pos<<1].max_r);
}
void build(long long pos,long long l,long long r){
    if(l==r){
        tr[pos].sum=tr[pos].max_l=tr[pos].max_m=tr[pos].max_r=0;
        return;
    }
    long long mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushup(pos);
}
Node query(long long pos,long long l,long long r,long long x,long long y){
    if(x<=l&&r<=y){
        return tr[pos];
    }
    long long mid = (l+r)>>1;
    if(mid>=y)return query(pos<<1,l,mid,x,y);
    else if(mid<x)return query(pos<<1|1,mid+1,r,x,y);
    else{
        Node ans,ans1=query(pos<<1,l,mid,x,y),ans2=query(pos<<1|1,mid+1,r,x,y);
        ans.max_l=max(ans1.max_l,ans1.sum+ans2.max_l);
        ans.max_m=max(max(ans1.max_m,ans2.max_m),ans1.max_r+ans2.max_l);
        ans.max_r=max(ans2.max_r,ans2.sum+ans1.max_r);
        return ans;
    }
}
void update(long long pos,long long l,long long r,long long x,long long val){
    if(l==r){
        tr[pos].sum=tr[pos].max_l=tr[pos].max_m=tr[pos].max_r=tr[pos].max_r+val;
        return;
    }
    long long mid = (l+r)>>1;
    if(mid>=x)update(pos<<1,l,mid,x,val);
    else update(pos<<1|1,mid+1,r,x,val);
    pushup(pos);
}
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        po[i].x=read(),po[i].y=read(),po[i].val=read();
    }
    sort(po+1,po+n+1,cmp2);
    for(long long i = 1;i<=n;i++){
        if(X.find(po[i].x)==X.end())X[po[i].x]=++x_idx;
        po[i].x=X[po[i].x];
    }
    sort(po+1,po+n+1,cmp1);
    for(long long i = 1;i<=n;i++){
        if(Y.find(po[i].y)==Y.end())Y[po[i].y]=++y_idx;
        po[i].y=Y[po[i].y];
    }
    build(1,1,x_idx);
    long long ans=0;
    for(long long y = 1;y<=y_idx;y++){
        while(po[poi].y==y){
            update(1,1,x_idx,po[poi].x,po[poi].val);
            poi++;
        }
        ans=max(ans,query(1,1,x_idx,1,x_idx).max_m);
    }
    cout<<ans;
    return 0;
}