#include<iostream>
using namespace std;
int main(){
    int n,x,y,flag=0,ans=0;
    cin>>n>>x;
    for(int i = 2;i<=n;i++){
        cin>>y;
        if(y<x){
            flag=1;
        }else if(y>x){
            if(flag){
                flag=0;
                ans++;
            }
        }
        x=y;
    }
    cout<<ans;
}