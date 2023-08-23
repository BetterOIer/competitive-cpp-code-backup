#include<iostream>
using namespace std;
long long ans=0;
long long qpow(long long  a,long long b){
    long long ans=1;
    for(long long i = 1;i<=b;i++){
        ans*=a;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    for(long long i = s.length()-1;i>=0;i--){
        ans=ans+1LL*(s[i]-'A'+1)*qpow(26,s.length()-1-i);
    }
    cout<<ans;
}