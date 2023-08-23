#include<iostream>
#include<algorithm>
using namespace std;
int a[10000000];
bool cmp(int a,int b){
    return b<a;
}
int main(){
    unsigned long long sum=0;
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(n<=k){
        cout<<0<<endl;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i<=k;i++){
        sum-=a[i];
    }
    cout<<sum<<endl;
    return 0;
}
