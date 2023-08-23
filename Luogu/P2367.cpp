#include<iostream>
#define MAXN 55
using namespace std;
int n,p,l,r,v;
int a[MAXN],cf[MAXN],ans=2147483647;
int main(){
    cin>>n>>p/* >>a[1] */;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cf[i]=a[i]-a[i-1];
    }
    for(int i = 1;i<=p;i++){
        cin>>l>>r>>v;
        cf[l]+=v;
        cf[r+1]-=v;
    }
    for(int i = 1;i<=n;i++){
        a[i]=a[i-1]+cf[i];
        ans=min(a[i],ans);
    }
    cout<<ans;
}