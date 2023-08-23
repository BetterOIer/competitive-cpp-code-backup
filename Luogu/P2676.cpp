#include<iostream>
#include<algorithm>
using namespace std;
int a[20001];
int main(){
    int n,b,ans = 0;
    cin>>n>>b;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(b>0){
        b-=a[n-(++ans)+1];
    }
    cout<<ans;
    return 0;
} 