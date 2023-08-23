#include<iostream>
using namespace std;
int a[500001],ans;
int main(){
    int L,M,N,Z,Y,H;
    cin>>L>>M>>N;
    for(int i = 1;i<=M;i++){
        cin>>a[i];
    }
    Z=0,Y=L;
    while(Z<=Y){
        H=Z+(Y-Z)/2;
        int po=0,take_away=0;
        for(int i = 1;i<=M;i++){
            if(a[i]-a[po]<H) take_away++;
            else po=i;
        }
        if(take_away<=N) Z=H+1,ans=H;
        else Y=H-1;
    }
    cout<<ans;
    return 0;
}