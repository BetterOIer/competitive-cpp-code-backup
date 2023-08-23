#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[70],b[70],c[80];
string jf(string s1,string s2){
    memset(a,0,70);
    memset(b,0,70);
    memset(c,0,80);
    int ws,ans;
    string s3;
    ws = s1.length();
    for(int i = s1.length()-1,j = 0;i>=0;--i,++j){
        a[i] = s1[j]-'0';
    }
    for(int i = s2.length()-1,j = 0;i>=0;--i,++j){
        b[i] = s2[j]-'0';
    }
    ws = s2.length()>ws? s2.length()-1:ws-1;
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
        char d = c[i]+'0';
        s3+=d;
    }
    cout<<s3<<endl;
    return s3;
}
string cf(string s1,string s2){
    memset(a,0,70);
    memset(b,0,70);
    memset(c,0,80);
    int ws1,ws2;
    string s3;
    ws1 = s1.length();
    for(int i = s1.length()-1,j = 0;i>=0;--i,++j){
        a[i] = s1[j]-'0';
    }
    for(int i = s2.length()-1,j = 0;i>=0;--i,++j){
        b[i] = s2[j]-'0';
    }
    ws2 = s2.length();
    if(s1=="0"||s2=="0"){
        return "0";
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
        char d = c[i]+'0';
        s3+=d;
    }
    return s3;
} 
int main(){
    int n,s = 1;
    string cfh="1",ans="1";
    cin>>n;
    for(int i = 2;i<=n;++i){
        int x = i;
        string s2;
        char y,z;
        if(x<10){
            y = x+'0';
            s2+=y;
        }else{
            y = x/10+'0';
            z = x%10+'0';
            s2+=y;
            s2+=z;
        }
        cfh = cf(cfh,s2);
        cout<<i<<" ";
        ans = jf(ans,cfh);
    }
    cout<<ans;
    return 0;
} 