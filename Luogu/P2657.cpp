#include <iostream>
#include <cstring>
using namespace std;
long long a[20]; 
long long dp[20][20]; 
long long dfs(long long pos, long long num, bool limit) {
	if(pos==-1) return 1; 
	if(!limit && dp[pos][num]!=-1) return dp[pos][num]; 
	long long high=limit?a[pos]:9; 
	long long ans=0; 
	for(long long i=0;i<=high;i++){
		if(i==0) ans+=dfs(pos-1,num,limit&&a[pos]==i); 
		else if(num!=3) ans+=dfs(pos-1,num+1,limit&&a[pos]==i);
    }
    if(!limit) dp[pos][num]=ans; 
    return ans;
}
long long divid(long long x) {
    for(int i = 0;i<=19;i++) for(int j = 0;j<=19;j++) dp[i][j]=-1;
	long long tot=0;
    while(x>0) a[tot++]=x%10,x/=10;
    return dfs(tot-1,0,true);
}

int main(){
	long long T; 
	cin>>T;
	while(T--){
		long long l,r;
		cin>>l>>r;
		cout<<divid(r)-divid(l-1)<<endl;
	}
	return 0;
}
