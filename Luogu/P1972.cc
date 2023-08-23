#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int tong[1000005],ans[1000005];
int main(){
    int n=read();
    for(int i = 1,num;i<=n;i++){
        num=read();
        if(!tong[num]){
            tong[num]++;
            ans[i]=ans[i-1]+1;
        }
    }
    int q=read();
    for(int i = 1,l,r;i<=q;i++){
        l=read(),r=read();
        printf("%d\n",ans[r]-ans[l-1]);
    }
}