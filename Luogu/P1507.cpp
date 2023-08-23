#include<iostream>
using namespace std;
int v[51],w[51],k[51],dp[450][450],W,V,N,flag=0;
int main(){
    cin>>V>>W>>N;

    for(int i = 1;i<=N;i++) cin>>v[i]>>w[i]>>k[i];
    for(int i = 1;i<=N;i++){
        for(int j = V;j>=v[i];j--){
            for(int h = W;h>=w[i];h--){
                dp[j][h]=max(dp[j][h],dp[j-v[i]][h-w[i]]+k[i]);
            }
        }
    }
    cout<<dp[V][W];
    return 0;
}