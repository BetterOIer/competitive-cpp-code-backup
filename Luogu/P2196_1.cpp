#include<iostream>
using namespace std;
long long dp[1000],val[200],map[25][25],n,k,pre[1000],ans=0;
void shuchu(int k){
    if(pre[k]==1)shuchu(pre[k]);
    cout<<pre[k]<<" ";
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>val[i];
    for(int i = 1;i<=n;i++){
        for(int w = i+1;w<=n;w++){
            cin>>map[i][w];
        }
    }
    dp[1]=val[1];
    for(int i = 2;i<=n;i++){
        for(int w = i-1;w>0;w--){
            if(map[w][i]&&dp[w]+val[i]>dp[i]){
                dp[i]=dp[w]+val[i];
                pre[i]=w;
            }
        }
        if(ans<dp[i]){
            ans=dp[i];
            k=i;
        }
    }
    shuchu(k);
    cout<<k<<endl<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}