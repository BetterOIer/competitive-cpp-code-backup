#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[330000],ans=0;
int main(){
    int n;
    cin>>n;
    cin>>a[1];
    ans+=a[1];
    for(int i = 2;i<=n;i++){
        long long p=200000000;
        cin>>a[i];
        for(int w = 1;w<i;w++)p=min(p,abs(a[w]-a[i]));
        ans+=p;
        
    }
    cout<<ans;
    return 0;
}