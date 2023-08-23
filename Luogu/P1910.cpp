#include<iostream>
using namespace std;
int pret[105],sala[105],dp[1005][1005],W,X,N,flag=0;
int main(){
    cin>>N>>W>>X;
    for(int i = 1;i<=N;i++) cin>>pret[i]>>sala[i];
    for(int i = 1;i<=N;i++){
        for(int j = W;j>=pret[i];j--){
            for(int h = X;h>=sala[i];h--){
                dp[j][h]=max(dp[j][h],dp[j-pret[i]][h-sala[i]]+1);
            }
        }
    }
    cout<<dp[W][X];
    return 0;
}