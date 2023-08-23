#include<iostream>
using namespace std;
long long ans=0;
int main(){
    int n,k;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>k;
        if(k==2){cout<<-1<<endl;continue;}
        if(k==3){cout<<1<<endl<<3<<endl;continue;}
        if(k==4){cout<<-1<<endl;continue;}
        if(k%2==0){cout<<3<<endl<<1<<" "<<(k-1)/2<<" "<<k<<endl;}
        else{cout<<3<<endl<<1<<" "<<(k-1)/2<<" "<<k-1<<endl;}
    }
    return 0;
}