#include<iostream>
using namespace std;
long long inv[3000006],p,n,i=2;
int main(){
    cin>>n>>p,inv[1]=1,printf("1");
    for(;i<=n;i++){
        inv[i]=(p-(p/i))*inv[p%i]%p;
        printf("\n%lld",inv[i]);
    }
}