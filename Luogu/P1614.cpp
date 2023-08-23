#include<iostream>
using namespace std;
int main(){
    int m, n,q,sum=0,ans;
    cin>>n>>m;
    q = n-m+1;
    int a[n+1];
    for(int i = 1;i<=n;++i){
        cin>>a[i];
    }
    for(int w = 1;w<=m;++w){
        sum+=a[w];
    }
    ans = sum;
    for(int w = 1;w<=q;++w){
        sum=sum-a[w]+a[w+m];
        if (ans>sum){
            ans = sum;
        }
    }
    cout<<ans;
    return 0;
} 