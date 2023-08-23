#include<iostream>
using namespace std;
long long squ=0, acr=0;
int main(){
    int n,m;
    cin>>n>>m;
    for(int x = 0;x<=n;x++){
        for(int y = 0;y<=m;y++){
            int dg=min(n-x,m-y)+min(x,y)+min(n-x,y)+min(x,m-y);
            squ+=dg;
            acr+=n*m-dg;
        }
    }
    cout<<squ/4<<" "<<acr/4;
}