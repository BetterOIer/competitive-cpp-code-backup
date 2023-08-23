#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
};
int a[10000000],tot=0;
int main(){
    int n=read();
    long long base=(1<<30);
    base<<=1;
    while(n>1){
        while(base>n){
            base>>=1;
        }
        while(n>=base){
            n-=base;
            a[++tot]=base;
        }
    }
    if(n==1){
        cout<<-1;
    }else{
        for(int i = 1;i<=tot;i++){
            cout<<a[i]<<" ";
        }
    }
}