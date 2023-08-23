#include<iostream>
using namespace std;
long long a;
string ans;
int main(){
    cin>>a;
    int ws = a/9;
    for(int i = 1;i<=ws;i++) ans+='9';
    char rest=a%9+'0';
    ans+=rest;
    cout<<ans<<" "<<ans;
}