#include<iostream>
using namespace std;
int a[101];
int main(){
    int n,p,q,r,s;
    cin>>n>>p>>q>>r>>s;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int len = q-p+1;
    for(int i = 0;i<len;i++){
        swap(a[p+i],a[r+i]);
    }
    for(int i = 1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}