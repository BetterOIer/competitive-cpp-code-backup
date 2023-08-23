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
int nex[100005],pat_len,s_len;
string s,pat;
void build_next(){
    nex[0]=0;int pre_len=0/* 最长相同前缀 */;
    for(int i = 1;i<pat_len;i++){
        while(pre_len && pat[i] !=pat[pre_len])pre_len=nex[pre_len];
        if(pat[i]==pat[pre_len])nex[i+1]=++pre_len;
    }
}
int search(){
    for(int i = 0,j=0;i<s_len;i++){
        while(j && s[i]!=pat[j])j = nex[j];
        if(s[i]==pat[j]) j++;
        if(j==pat_len) return i-pat_len+2;/* 返回相同子串开始的地方(这里第一位是1) */
    }
    return -1;
}
int main(){
    cin>>s>>pat;
    s_len = s.length(),pat_len = pat.length();
    build_next();
    int sta=search();
    if(sta==-1)cout<<"Not found."<<endl;
    else cout<<sta<<endl;
    return 0;
}