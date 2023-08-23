/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#define max(a,b) (a)>(b)? (a):(b)
#define min(a,b) (a)<(b)? (a):(b)
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int mx[100005][20];
int loog[100005];
void check(int l,int r){
    int po=loog[r-l+1];
    printf("%d\n",(int)(max(mx[l][po],mx[r-(1<<po)+1][po])));
}
int main(){
    n=read(),m=read();
    for(int i = 2;i<=n;i++){
        loog[i]=loog[(i>>1)]+1;
    }
    for(int i = 1;i<=n;i++){
        mx[i][0]=read();
    }
    int bit=loog[n];
    for(int j = 1;j<=bit;j++){
        for(int i = 1;i<=n-(1<<j)+1;i++){
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i = 1,l,r;i<=m;i++){
        l=read(),r=read();
        check(l,r);
    }
    return 0;
}