#include<iostream>
#include<string>
using namespace std;
int a[510],b[510],c[510];
int main(){
    string s;
    int ws,ans;
    cin>>s;
    ws = s.length();
    for(int i = s.length()-1,j = 0;i>=0;--i,++j){
        a[i] = s[j]-'0';
    }
    cin>>s;
    for(int i = s.length()-1,j = 0;i>=0;--i,++j){
        b[i] = s[j]-'0';
    }
    ws = s.length()>ws? s.length()-1:ws-1;
    int i = 0;
    for(;i<=ws;i++){
        c[i] = c[i]+a[i]+b[i];
        if(c[i]>9){
            c[i+1]+=c[i]/10;
            c[i]= c[i]%10;
        }
    }

    ans = c[i]!=0? i+1:i;
    for(int i = ans-1;i>=0;i--){
        cout<<c[i];
    }
    return 0;
} 