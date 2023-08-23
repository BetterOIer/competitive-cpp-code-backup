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
int m,ne[1000005];
void get_next(){
    for (int i = 1, j = 0; i < m; i ++ ){
        while (j && s[i] != s[j]) j = ne[j];
        if (s[i] == s[j]) j++,ne[i+1] =j;
    }
}
int main(){
    while(true){
        cin>>s;
        if(s==".")break;
        m=s.length();
        get_next();
        /* int maxn = 0;
        for(int i = 1;i<=m;i++)maxn=max(maxn,ne[i]); */
        if(m%(m-ne[m])==0)cout<<m/(m-ne[m])<<endl;
        else cout<<1<<endl;
        for(int i = 1;i<=m;i++)ne[i]=0;
    }
    return 0;
}