//About 20pts 
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,q,opt,l,r,x;
int num[100005];
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    n=read(),q=read();
    for(int i = 1;i<=n;i++) num[i]=read();
    while(q--){
        opt=read(),l=read(),r=read(),x=read();
        if(opt==0&&x==0) continue;
        for(int i = l;i<=r;i++){
            num[i]=num[i]^(x+(i-l)*opt);
        }
    }
    for(int i = 1;i<=n;i++) cout<<num[i]<<" ";
    return 0;
}