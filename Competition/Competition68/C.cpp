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
int m,p;
int a[1005],ans=0;
bool ok[7];
void dfs(int pos,int ori){
    if(pos==m){
        for(int i = 0;i<=6;i++)ok[i]=false;
        for(int i = 0;i<m;i++){
            ok[a[i]%7]=true;
        }
        for(int i = 0;i<=6;i++){
            if(!ok[i])return;
        }
        return (ans+=1)%=p,void();
    }
    a[pos]=ori;
    for(int i = 0;i<=9;i++){
        dfs(pos+1,ori*10+i);
    }
}
int main(){
    m=read(),p=read();
    dfs(0,0);
    cout<<ans;
    return 0;
}