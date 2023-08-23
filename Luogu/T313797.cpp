/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 长城之上，是千亿的星空，星空之上，是不灭的守望。
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
/* #include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    long long val;
    long long minn;
    long long maxn;
}tree[1000005];
void pushup(long long pos){
    tree[pos].minn=min(tree[pos<<1].minn,tree[pos<<1|1].minn);
    tree[pos].maxn=max(tree[pos<<1].maxn,tree[pos<<1|1].maxn);
}
void build(long long pos,long long l,long long r){
    if(l==r){
        tree[pos].maxn=tree[pos].minn=tree[pos].val=read();
        return;
    }
    long long mid= (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushup(pos);
}
node query(long long pos,long long l,long long r,long long x,long long y){
    if(x<=l&&r<=y)return tree[pos];
    long long mid = (l+r)>>1;
    long long ansb = 0,ansm=2147483647;
    node ln,ansn;
    if(mid>=x) {ln=query(pos<<1,l,mid,x,y);ansb=max(ln.maxn,ansb);ansm=min(ln.minn,ansm);}
    if(mid<y) {ln=query(pos<<1|1,mid+1,r,x,y);ansb=max(ln.maxn,ansb);ansm=min(ln.minn,ansm);}
    ansn.maxn=ansb,ansn.minn=ansm;
    return ansn;
}
int main(){
    long long n=read(),q=read();
    build(1,1,n);
    for(long long i = 1,l,r;i<=q;i++){
        l=read(),r=read();
        node ans=query(1,1,n,l,r);
        cout<<ans.maxn-ans.minn<<endl;
    }
}
 */
#include<iostream>
using namespace std;
inline int read(){
	int long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
int f[2][17][50004],lg[50004];
int main(){
    n=read(),m=read();
    for(int i=2;i<=n;i++){
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1;i<=n;i++){
        f[1][0][i]=f[0][0][i]=read();
    }
    for(int k=1;k<=lg[n];k++){
        for(int i=1;i+(1<<k)-1<=n;i++){
            f[0][k][i]=max(f[0][k-1][i],f[0][k-1][i+(1<<k-1)]);
            f[1][k][i]=min(f[1][k-1][i],f[1][k-1][i+(1<<k-1)]);
        }
    }
    while(m--){
        int l=read(),r=read();
        printf("%d\n",max(f[0][lg[r-l+1]][l],f[0][lg[r-l+1]][r-(1<<lg[r-l+1])+1])-min(f[1][lg[r-l+1]][l],f[1][lg[r-l+1]][r-(1<<lg[r-l+1])+1]));
    }
}