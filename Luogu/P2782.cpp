#include<iostream>
#include<algorithm>
using namespace std;
struct connect{
	int s,n;
}lj[200005]; 
bool comp(connect x,connect y){
	return x.s<y.s;
}
int ans=1,dp[200005];
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>lj[i].s>>lj[i].n;
	}
	sort(lj+1,lj+n+1,comp);
    dp[1]=lj[1].n;
	for(int i = 2;i<=n;i++){
        /* for(int j = i-1;j>=1;j--){
            if(lj[i].n>lj[j].n){
                lj[i].dis=max(lj[j].dis+1,lj[i].dis);
            }
        }
        ans=max(ans,lj[i].dis); */
        int NBESTWYYDS=upper_bound(dp+1,ans+dp+1,lj[i].n)-dp;
        dp[NBESTWYYDS]=lj[i].n;
        if(NBESTWYYDS>ans)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
} 