#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,k;
int main(){
    freopen("rebuild.in","r",stdin);
    freopen("rebuild.out","w",stdout);
    n=read(),k=read();
    
    return 0;
}