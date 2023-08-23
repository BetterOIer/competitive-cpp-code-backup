#include<iostream>
using namespace std;
int main(){
    long long n,m;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>m;
        if(m<=1)cout<<"dog wins"<<endl;
        else{if((m-1)/2%2==0)cout<<"dog wins"<<endl;
        else cout<<"pig wins"<<endl;}
    }
    return 0;
}

