#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,y,ans=0;
    cin>>x>>y;
    while(x&&y){  
        swap(x,y);  
        ans+=4*y*(x/y); 
        x%=y;   
    }
    cout<<ans;
    return 0;
}