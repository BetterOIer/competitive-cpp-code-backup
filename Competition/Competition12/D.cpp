#include<bits/stdc++.h>
using namespace std;
int gz[500001],po[500001];
int dp[10000005];
bool cango[10000005]={true};
int main(){
    int n,d,k,num;
    cin>>n>>d>>k;
    for(int i = 1;i<=n;i++){
        cin>>po[i]>>num;
        gz[i]=num;
    }
    for(int i = 0;i<=po[n]-d;i++){
        memset (cango,false,sizeof(cango));
        memset (dp,0,sizeof(dp));
        cango[0]=true;
        for(int j = 1;j<=n;j++){
             for(int w = d+i;w>=d-i;w--){
                if(po[j]-w>=0&&cango[po[j]-w]){
                    if(!cango[po[j]]){
                        cango[po[j]]=true;
                        dp[po[j]]=dp[po[j]-w];
                    }else{
                        dp[po[j]]=max(dp[po[j]-w],dp[po[j]]);
                    }
                }
            }
            if(cango[po[j]]) dp[po[j]]+=gz[j];
            if(dp[po[j]]>=k){
                cout<<i;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}