#include<iostream>
using namespace std;
long long a,b,f[1001][1001],p,q;
long long gcd(long long  m, long long n){
    while (n != 0){
	    long long t = m % n;
	    m = n;
	    n = t;
	}
    return m;
}
int main(){
    scanf("%lld%lld",&a,&b);
    for(int i=1;i<=a;i++) scanf("%lld",&f[i][i]);
    for(int i=a-1;i>=1;i--){
        for(int j=i+1;j<=a;j++){
            f[i][j]=gcd(f[i][i],f[i+1][j]);
        }
    }
    for(int i=1;i<=b;i++){
        scanf("%lld%lld",&p,&q),
        printf("%lld\n",f[p][q]);
    }
}
