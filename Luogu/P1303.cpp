#include<iostream>
#include<string>
using namespace std;
int a[2100],b[2100],c[4200];
int main(){
    string s1,s2;
    int ws1,ws2;
    cin>>s1;
    ws1 = s1.length();
    for(int i = s1.length()-1,j = 0;i>=0;--i,++j){
        a[i] = s1[j]-'0';
    }
    cin>>s2;
    for(int i = s2.length()-1,j = 0;i>=0;--i,++j){
        b[i] = s2[j]-'0';
    }
    ws2 = s2.length();
    if(s1=="0"||s2=="0"){
        cout<<0;
        return 0;
    }
    int i = 0,j = 0;
    for(;i<=ws1-1;i++){
        j = 0;
        for(;j<=ws2-1;j++){
            c[i+j] = c[i+j]+a[i]*b[j];
            if(c[i+j]>9){
                c[i+j+1]+=c[i+j]/10;
                c[i+j]= c[i+j]%10;
            }
        }
    }
    int t = i+j-1;
    while(c[t]>9){
        c[t+1]+=c[t]/10;
        c[t]= c[t]%10;
        t++;
    }
    int ans = c[t]==0? t-1:t;
    for(int i = ans;i>=0;i--){
        cout<<c[i];
    }
    return 0;
} 