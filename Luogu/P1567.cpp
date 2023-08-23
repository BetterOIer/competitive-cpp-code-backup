#include<iostream>
using namespace std;
int main(){
    int n,before=-1,now,k=0,K=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>now;
        if(now>=before){
            k++;
            K=max(k,K);
        }
        else{
            k=1;
        }
        before=now;
    }
    cout<<K;
}