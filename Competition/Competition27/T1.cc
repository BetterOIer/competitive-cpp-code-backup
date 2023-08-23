#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int mod=998244353;
int a[5050];
long long ans;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int p1=1,p2=3;
    while(p1<=n-2){
        if(a[p1]+a[p1+1]>a[p2]){
            ans=(ans+1)%mod;
            p2++;
        }
        else{
            p1++;
            p2=p1+2;
        }
    }
    cout<<ans%mod;
}