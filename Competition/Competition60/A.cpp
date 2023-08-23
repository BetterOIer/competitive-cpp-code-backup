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
int a,b,c;
int main(){
    string s;
    cin>>s;
    for(int i = 0;i<s.length();i++){
        if('0'<=s[i]&&s[i]<='9')a++;
        if('a'<=s[i]&&s[i]<='z')b++;
        if('A'<=s[i]&&s[i]<='Z')c++;
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}