#include<iostream>
using namespace std;
int ti_t[12],zy_t[12],zy_n[12],dp1[160],dp2[160];
int main(){
    int n,m,r,k;
    cin>>n>>m>>k>>r;
    for(int i = 1;i<=n;i++)cin>>ti_t[i];
    for(int i = 1;i<=m;i++)cin>>zy_t[i];
    for(int i = 1;i<=m;i++)cin>>zy_n[i];
    for(int i = 1;i<=m;i++){
        for(int w = r;w>=zy_t[i];w--){
            dp1[w]=max(dp1[w],dp1[w-zy_t[i]]+zy_n[i]);
        }
    }
    for(int i=0;i<=r;i++){
		if(dp1[i]>=k){
			r-=i;
			break;
		}
	}
    for(int i = 1;i<=n;i++){
        for(int w = r;w>=ti_t[i];w--){
            dp2[w]=max(dp2[w],dp2[w-ti_t[i]]+1);
        }
    }
    cout<<dp2[r];
    return 0;
}