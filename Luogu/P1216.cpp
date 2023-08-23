#include<iostream>
using namespace std;
int a[1001][1001];
int main(){
    int n;cin>>n;
    for(int i= 1;i<=n;i++)for(int w = 1;w<=i;w++)cin>>a[i][w];
    for(int i = n;i>=1;i--)for(int w = 1;w<=i-1;w++)a[i-1][w]+=max(a[i][w],a[i][w+1]);
    cout<<a[1][1];
    return 0;
}