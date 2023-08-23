#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int to;
    int val;
};
vector<node> po[100005];
int h[1004],dp[1004][1004][2],tmp[1004][2],n,m,k;/*对于i为根的tree,有j个节点被bighead干掉，1好节点是否被大头干掉*/
void dfs(int now,int fa){
    dp[now][0][0]=dp[now][1][1]=0;
    for(node i:po[now]){
        if(i.to==fa)continue;
        dfs(i.to,now);
        memcpy(tmp,dp[now],sizeof(dp[now]));
		memset(dp[now],0x3f3f3f3f,sizeof(dp[now]));
        for(int j=0;j<=k;++j){
			for(int t=0;t<=j;++t){
				dp[now][j][0]=min(dp[now][j][0],min(dp[i.to][t][0]+tmp[j-t][0]+(m==2)*i.val,dp[i.to][t][1]+tmp[j-t][0]));
				dp[now][j][1]=min(dp[now][j][1],min(dp[i.to][t][1]+tmp[j-t][1]+i.val,dp[i.to][t][0]+tmp[j-t][1]));
			}
		}
    }
}
int main(){
    memset(dp,0x3f3f3f3f,sizeof(dp));
    n=read(),m=read(),k=read();
    for(int i = 1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        po[u].push_back((node){v,w});
        po[v].push_back((node){u,w});
    }
    if(n-k+1<m){cout<<"-1\n";return 0;}
    dfs(1,0);
    cout<<dp[1][k][1];
    return 0;
}
