#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long ans=1;
    for(int i = 3;i<=n+1;i++){
        ans=(ans*i)%998244353;
    }
    cout<<ans;
}