#include<iostream>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int a[5005],k,n,xl[5005];
long long ANS=1;
void check(int nowk,int nowpo){
    if(nowk==k+1){
        int ans=1;
        for(int i = 2;i<=k-1;i++) ans*=xl[i];
        ANS=ANS*ans%mod;
        return;
    }
    for(int i = nowpo+1;i<=n-(k-nowk);i++){
        xl[nowk]=a[i];
        check(nowk+1,i);
    }
}
int main(){
    cin>>n>>k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    check(1,0);
    cout<<ANS;
}