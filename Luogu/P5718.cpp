#include<iostream>
using namespace std;
int main(){
    int mina = 1000, a, n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a;
        if(a<mina){
            mina = a;
        }
    }

    cout<<mina;
    return 0;
} 