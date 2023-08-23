#include<iostream>
using namespace std;
long long a[10002],ans = 0;
int main(){
    int n,x;
    cin>>n>>x;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        int k = a[i-1]+a[i]>x? a[i-1]+a[i]-x:0;
        a[i]-=k;
        ans+=k;
    }
    cout<<ans;
    return 0;
} 