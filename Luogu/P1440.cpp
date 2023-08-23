#include<iostream>
using namespace std;
int a[100005];
struct node{int l,r;long long val;}tree[6000005];
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
inline void write(long long x){if(x<0) putchar('-'),x=-x;if(x>9) write(x/10);putchar(x%10+'0');}
inline long long MIN(long long a,long long b){return a<b? a:b;}
inline void pushup(int pos){
    tree[pos].val=MIN(tree[pos<<1].val,tree[pos<<1|1].val);
}
inline long long query(int x,int y,int pos){
    if(x<=tree[pos].l&&y>=tree[pos].r) return tree[pos].val;
    int mid=(tree[pos].l+tree[pos].r)>>1;
    long long ans=9223372036854775807ll;
    if(mid>=x)ans=MIN(ans,query(x,y,pos<<1));
    if(mid<y)ans=MIN(ans,query(x,y,pos<<1|1));
    return ans;
}
inline void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r){
        tree[pos].val=read();
        return;
    }
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
    return;
}
int main(){
    int n,m;
    n=read(),m=read();
    build(1,1,n);
    write(0);
    for(int i = 2;i<=n;i++){
        puts("");
        write(query((i-m>0? i-m:1),i-1,1));
    }
}