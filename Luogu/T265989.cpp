#include<iostream>
#include<algorithm>
using namespace std;
int a[2000006];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long s=a[1],b=a[n];
    if(abs(s)>abs(b)){
        for(int i = 1;i<=m;i++){
            s=min(s-2,s*2);
        }
    }else{
        for(int i = 1;i<=m;i++){
            b=max(b+2,b*2);
        }
    }
    cout<<b-s;
}