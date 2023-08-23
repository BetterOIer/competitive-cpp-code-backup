#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int N = 305;
int n,m;
struct node{
    int score;
    vector<int>sons;
}tree[N];
int dp[N][N];
void tdp(int pos){
    dp[pos][0]=0;
    for(int i:tree[pos].sons){
        tdp(i);
        for(int t = m;t>=0;t--){
            for(int j=1;j<=t;j++){
                dp[pos][t]=max(dp[pos][t],dp[pos][t-j]+dp[i][j]);
            }
        }
    }
    for(int t = m;t>0;t--){
        dp[pos][t]=dp[pos][t-1]+tree[pos].score;
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1,fa,score;i<=n;i++){
        fa=read();
        score=read();
        tree[fa].sons.push_back(i);
        tree[i].score=score;
    }
    m++;
    tdp(0);
    cout<<dp[0][m];
    return 0;
}