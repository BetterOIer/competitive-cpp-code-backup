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
struct node{
    int to;
    int costs;
}tra[8][4]={{0,0,0,0},{0,0,1,2},{0,1,0,1},{0,2,1,0}},n;
int T(char c){
    if(c=='B')return 2;
    if(c=='W')return 3;
    if(c=='R')return 1;
    return -1;
}
int main(){
    n=read();
    string s;
    cin>>s;
    int last=3,ans=0;
    for(int i = 0;i<n;i++){
        int req = T(s[i]);
        ans+=tra[last][T(s[i])];
        last=T(s[i]);
    }
    cout<<ans;
    return 0;
}