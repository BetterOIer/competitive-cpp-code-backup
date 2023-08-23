#include<iostream>
using namespace std;
int a[100005],n,m,l,r;
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cin>>m;
    for(int i = 1;i<=m;i++){
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;
    }
}