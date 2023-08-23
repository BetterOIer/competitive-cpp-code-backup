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
char s[1000005];
int len,d[1000005]={0,1},ans;
inline void readin(){
    s[0]='$', s[len = 1]='#';
    char c=getchar();
    while(c<'a'||c>'z')c = getchar();
    while(c>='a'&&c<='z') s[++len]=c, s[++len]='#', c=getchar();
}
void get_d(){
    for(int i = 2,l = 1,r = 1;i<len;i++){
        if(i<=r)d[i] = min(d[l+r-i],r-i+1);
        while(s[i-d[i]]==s[i+d[i]])d[i]++;
        if(i+d[i]-1>r){
            if(i&1)for(int j=max(r,i+4);j<i+d[i];j++)
				if(!((j-i)&3) && d[i-(j-i)/2]>(j-i)/2)ans=max(ans,j-i);
            l = i-d[i]+1,r=i+d[i]-1;
        }
    }
}
int main(){
    len=read(); readin(); get_d();
    cout<<ans;
    return 0;
}