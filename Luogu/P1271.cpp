#include<iostream>
using namespace std;
int a[1000];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int b;
        cin>>b;
        a[b]++;
    }
    for(int i = 1;i<=n;i++){
        while(a[i]!=0){
            cout<<i<<" ";
            a[i]--;
        }
    }
    return 0;
} 