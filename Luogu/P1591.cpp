#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[7000],b[7000],c[8000];
char d[5];
string cf(string s1,string s2){
    memset(a,0,7000);
    memset(b,0,7000);
    memset(c,0,8000);
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
    //cout<<cf("00004254367435000000000000000000000000000000","4254367435000000000000000000000000000000");
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int m;
        char k;
        cin>>m>>k;
        string s1="1";
        if(m==1) s1 = "1";
        else{
            for(int i = 2;i<=m;i++){
                string s2;
                int x = i,ans = 0;
                while(x!=0){
                    d[++ans] = x%10+'0';
                    x/=10;
                }
                for(int i = ans;i>0;i--){
                    s2+=d[i];
                }
                s1 = cf(s1,s2);
            }
        }
        int ans=0;
        cout<<endl<<s1<<endl;
        for(int i = 0;i<=s1.length()-1;i++){
            if(s1[i]==k) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
} 