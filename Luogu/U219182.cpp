#include<iostream>
#include<algorithm>
using namespace std;
int a[10005];
long long ans=0;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int M;
    if(n%2==1) M=a[n/2+1];
    else M=(a[n/2+1]+a[n/2])>>1;
    for(int i = 1;i<=n;i++) ans+=abs(a[i]-M);
    cout<<ans;
    return 0;
}