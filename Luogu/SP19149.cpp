#include<iostream>
#include<cstdio>
using namespace std;
const long long p=1000000007;
int q,n,t;
long long f[400][400],c[400][400];
int main()
{
    cin>>q;
    for(int i=0;i<=300;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
    }

    f[0][0]=1;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100-j;k++)f[i+1][j+k]=(f[i+1][j+k]+((c[2*k][k]*c[2*(j+k)][2*k])%p*f[i][j])%p)%p;
        }
    }

    while(q--){
        cin>>n>>t;
        if(t%2!=0) cout<<"0"<<endl;
        else printf("%lld\n",f[n][t/2]);
    }
    return 0;
 } 
