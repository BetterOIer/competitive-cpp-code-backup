/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
#define refer127 2139062143
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int g[5000][5000];
int main(){
    freopen("in.in","r",stdin);
    int t=read();
    while(t--){
        memset(g, 127, sizeof g);
        n = read();
        for(int i = 1;i<=n;i++){
            string s;
            cin>>s;
            for(int j= 0;j<n;j++){
                if(s[j]-'0'==1) g[i][j+1]=1;
            }
        }
        for(int i = 1;i<=n;i++) g[i][i]=0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(g[j][i]!=0&&g[j][i]!=refer127){
                    for(int w = 1;w<=n;w++){
                        if(g[i][w]!=refer127){
                            if(g[j][w]>g[j][i]+g[i][w]){
                                g[j][w]=g[j][i]+g[i][w];
                            }
                        }
                    }
                }
            }
        }
        int ans=2147483647;
        for(int i = 1;i<=n;i++){
            int ans1=0;
            for(int j = 1;j<=n;j++){
                ans1=max(ans1,g[i][j]);
            }
            ans=min(ans,ans1);
        }
        cout<<ans<<endl;
    }
    return 0;
}