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
int n;
string s;
string pi="314159265358979323846264338327";
int main(){
    n=read();
    while(n){
        cin>>s;
        for(int i = 0;i<=29;i++){
            if(pi[i]!=s[i]){
                cout<<i<<endl;
                goto ge;
            }
        }
        cout<<30<<endl;
        ge:
        n--;
    }
    return 0;
}