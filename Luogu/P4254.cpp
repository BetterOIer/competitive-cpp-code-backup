#include<iostream>
#include<cstring>
using namespace std;
void exgcd(int a, int b, int &x, int &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    int q=a/b,r=a%b;
    exgcd(b,r,x,y);
    y-=q*x;
}
const int MAX_N=100000005;
int v[MAX_N],prime[MAX_N],m;
void primes(int n){
    memset(v,0,sizeof(v));
    m=0;
    for(int i = 2;i<=n;i++){
        if(v[i]==0){
            v[i]=i;
            prime[++m]=i;
        }
        for(int j = 1;j<=m;j++){
            if(prime[i]>v[i]||prime[j]*i>n) break;
            v[i*prime[j]]=prime[j];
        }
    }
    for(int i =1;i<=m;i++) cout<<prime[i]<<endl;
}
int main(){
    primes(100000005);
}