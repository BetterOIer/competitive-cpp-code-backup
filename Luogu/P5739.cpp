#include<iostream>
using namespace std;
int jc(int a){
    if(a==1){
        return 1;
    }
    return(jc(a-1)*a);
}
int main(){
    int n;
    cin>>n;
    cout<<jc(n);
    return 0;
}