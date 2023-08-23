#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
char n1,n2;
int rea[30];
int main(){
    n=read(),m=read();
    for(int i = 1;i<=m;i++){
        scanf("%s<%s",&n1,&n2);
        
    }
    return 0;
}