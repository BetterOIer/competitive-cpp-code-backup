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
int n,m;
int val[3005],wei[3005];
int dp[3005][3005],minn[3005][3005],num[3005][3005],ans[3005][3005];
bool legal[3005][3005];
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        wei[i]=read(),val[i]=read();
    }
    /* for(int i = 1;i<=n;i++){
        for(int j = m;j>=wei[i];j--){
            if(dp[j]<dp[j-wei[i]]+val[i]){
                if(i-minn[j-wei[i]]+1>num[j-wei[i]]+1){
                    dp[j] = dp[j-wei[i]]+val[i];
                    num[j]=num[j-wei[i]]+1;
                    if(!num[j-wei[i]])minn[j] = i;
                    else minn[j] = minn[j-wei[i]];
                }
            }
        }for(int j = 1;j<=m;j++){
            cout<<dp[j]<<' ';
        }
        puts("");
    } */
    memset(minn,127,sizeof minn);
    int tot = 0;
    for(int i = 1;i<=n;i++){
        tot+=wei[i];
        for(int j = tot;j>=1;j--){
            if(dp[i-1][j]<=dp[i-1][j-wei[i]]+val[i]&&j-wei[i]>=0){
                dp[i][j] = dp[i-1][j-wei[i]]+val[i];
                if(minn[i-1][j-wei[i]]==refer127)num[i][j]=1,minn[i][j] = i;
                else num[i][j]=num[i-1][j-wei[i]]+1,minn[i][j] = minn[i-1][j-wei[i]];
                if(i-minn[i][j]+1>num[i][j]+1)legal[i][j]=true;
                else legal[i][j]=false;
            }else{
                dp[i][j] = dp[i-1][j];
                num[i][j] = num[i-1][j];
                minn[i][j] = minn[i-1][j];
                legal[i][j] = legal[i-1][j];
            }
            for(int k = i-1;k>=0;k--){
                if(i-minn[k][j-wei[i]]+1>num[k][j-wei[i]]+1/* legal[k][j-wei[i]] */){
                    ans[i][j] = dp[k][j-wei[i]]+val[i];
                    break;
                }
            }
        }
    }
    cout<<"minn\n";
    for(int i= 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<minn[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"===\n";
    cout<<"num\n";
    for(int i= 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"===\n";
    cout<<"dp\n";
    for(int i= 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"===\n";
    cout<<"ans\n";
    for(int i= 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"===\n";
    for(int i = 1;i<=m;i++){
        cout<<ans[n][i]<<" ";
    }
    return 0;
}