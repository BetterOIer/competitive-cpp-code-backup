#include<bits/stdc++.h>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long t,n;
struct tree{
    long long v,w,sum;
}tr[1000005];
bool cmp1(tree a,tree b){
    if(a.v!=b.v)return a.v<b.v;
    return a.w<b.w;
}
bool cmp(tree a,tree b){
    if(a.w!=b.w)return a.w>b.w;
    return a.v<b.v;
}
bool cmp2(tree a,tree b){
    if(a.sum!=b.sum)return a.sum>b.sum;
    else return a.v>b.v;
}
long long minn;
int main(){
    t=read();
    while(t--){
        n=read();
        for(long long i=1;i<=n;i++){
            tr[i].v=read();
            tr[i].w=read();
            tr[i].sum=tr[i].v+tr[i].w;
        }
        minn=0x3f3f3f3f;
        sort(tr+1,tr+n+1,cmp1);
        sort(tr+1,tr+n/2,cmp);
        sort(tr+n/2+1,tr+n+1,cmp2);
        long long mid=n/2;
        for(long long i=1;i<=mid;i++){
            minn=min(minn,max(tr[i].v,min(tr[i+mid].sum-tr[i].w,tr[i+mid].v)));
        }
        for(long long i=mid+1;i<=n;i++){
            minn=min(minn,tr[i].v);
        }
        cout<<minn<<endl;
    }
}
