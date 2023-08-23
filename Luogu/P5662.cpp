#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    int T=read(),n=read(),m=read();
    for(int i=1;i<=T;i++){
        for(int j = 1;j<=n;j++){

        }
    }
}