#include<iostream>
using namespace std;
int main(){
    int htt, sum=0, h[10];
    for(int i=1;i<=10; ++i){
        cin>>h[i];
        }
    cin>>htt;
    for(int i=1;i<=10; ++i){
        if(h[i]<=(htt+30)){
            sum++;
        }
    }
    cout<<sum;
}