/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
string s,s1,s1R;
int main(){
    cin>>s;
    int len = s.length(),cnt=0;
    for(int i = 0;i<len>>1;i++){
        cnt+=(s[i]!=s[0]);
    }
    if(!cnt)cout<<"Impossible"<<endl;
    else{
        for(int i = 1;i<=(len>>1);i++){
            s1 = s.substr(i,len-i+1)+s.substr(0,i);
            s1R = s1;reverse(s1R.begin(),s1R.end());
            if(s1R==s1&&s1R!=s){cout<<1<<endl;return 0;}
        }
        cout<<2<<endl;
    }
    return 0;
}
