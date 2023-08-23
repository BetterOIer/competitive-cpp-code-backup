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
string s;
int len,d[20000002]={0,1};
void get_d(){
    for(int i = 2,l = 1,r = 1;i<len;i++){
        if(i<=r)d[i] = min(d[l+r-i],r-i+1);
        while(s[i-d[i]]==s[i+d[i]])d[i]++;
        if(i+d[i]-1>r)l = i-d[i]+1,r=i+d[i]-1;
    }
}
int main(){
    cin>>s;len = s.length();
    for(int i = 0;i<=2*len;i+=2){
        s.insert(i,1,'#');
    }s.insert(0,1,'$');len = s.length();
    get_d();
    int maxn = 0;
    for(int i = 0;i<len;i++){
        maxn = max(maxn,d[i]);
    }
    cout<<maxn-1;
    return 0;
}