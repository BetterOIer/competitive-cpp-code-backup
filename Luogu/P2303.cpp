#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long ans=n;
    int t=sqrt(n);
    for(long long i = 2;i<=t;i++){
        if(n%i==0){
            int b=0;
            while(n%i==0){
                ++b,n/=i;
            }
            ans/=i;
            ans*=(b+1)*i-b;
        }
    }
    if(n>1) ans/=n,ans*=(n<<1)-1;
    printf("%lld",ans);
}