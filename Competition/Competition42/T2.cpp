#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int numa,numb;
int main(){
    int n=read();
    for(int i = 1,k;i<=n;i++){
        k=read();
        if(k==1)numa++;
        else numb++;
    }
    while(numa&&numb){
        cout<<1<<" "<<-1<<" ";
        numa--,numb--;
    }
    while(numa){
        cout<<1<<" ";
        numa--;
    }
    while(numb){
        cout<<-1<<" ";
        numb--;
    }
    return 0;
}