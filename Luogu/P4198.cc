#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
double ma[100005<<2];
int ans[100005<<2];
int calc(int pos,int l,int r,double maxv){
    if(l==r)return ma[pos]>maxv;
    int mid = (l+r)>>1;
    return ma[pos<<1]<=maxv? calc(pos<<1|1,mid+1,r,maxv):ans[pos]+calc(pos<<1,l,mid,maxv);
}
void update(int pos,int l,int r, int rt, double val){
    if(l==r) return (void)(ma[pos]=val);
    int mid = (l+r)>>1;
    (mid>=rt?update(pos<<1,l,mid,rt,val):update(pos<<1|1,mid+1,r,rt,val));
    ma[pos] = max(ma[pos<<1],ma[pos<<1|1]);
    ans[pos] = calc(pos<<1|1,mid+1,r,ma[pos<<1]);
}
int main(){
    n=read(),m=read();
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();update(1,1,n,x,1.0*y/x);
        printf("%d\n",calc(1,1,n,0));
    }
}