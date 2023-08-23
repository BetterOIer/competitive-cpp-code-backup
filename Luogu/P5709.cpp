#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int m,t,s;
    cin>>m>>t>>s;
    if(t==0)cout<<0;
    else if(t*m<=s) cout<<0;
    else if(t*m>s){
        int n=ceil(1.0*s/t);
        cout<<m-n;
    }
}