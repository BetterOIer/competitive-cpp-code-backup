#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int x;
    int y;
}point[1000005];
bool cmp(node a,node b){
    return a.x<b.x;
}
int dp[1000005];
int main(){
    int n=read();
    int tot=0;
    for(int i = 1,u,v;i<=n;i++){
        u=read(),v=read();
        if(u<0||v<0)continue;
        point[++tot].x=u,point[tot].y=v;
    }
    sort(point+1,point+tot+1,cmp);
    int ans=0;
    /* for(int i = 1; i <= tot; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++){
			if(point[i].y >= point[j].y && (dp[j] + 1 > dp[i])){
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans ,dp[i]);
	} */
    for(int i=1;i<=tot;i++){
        if(point[i].y>=dp[ans]) dp[++ans]=point[i].y;
        else{
            int temp=lower_bound(dp+1,dp+1+ans,point[i].y)-dp;
            dp[temp]=point[i].y;
        }
    }
    cout<<ans;
}