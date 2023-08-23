/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int main(){
    string s1,s2,opt,ans;
    cin>>s1>>s2>>opt;
    if(s1.length()>s2.length())swap(s1,s2);
    while(s1.length()<s2.length())s1="0"+s1;
    int len=s1.length();
    if(opt=="and"){
        for(int i = 0;i<len;i++){
            ans+=('0'+((s1[i]-'0')&(s2[i]-'0')));
        }
    }else if(opt=="or"){
        for(int i = 0;i<len;i++){
            ans+=('0'+((s1[i]-'0')|(s2[i]-'0')));
        }
    }else if(opt=="xor"){
        for(int i = 0;i<len;i++){
            ans+=('0'+((s1[i]-'0')^(s2[i]-'0')));
        }
    }
    while(ans[0]=='0')ans=ans.substr(1,ans.length()-1);
    cout<<ans<<endl;
    return 0;
}