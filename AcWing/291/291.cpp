#include<iostream>
using namespace std;
const int maxn = (1<<11);
int n,m;
long long dp[12][maxn];
bool in_s[maxn];
int main(){
	while(cin>>n>>m&&n){
		for(int i = 0;i<1<<m;i++){
			bool cnt=0,has_odd=0;
			for(int j = 0;j<m;j++){
				if(i>>j&1)has_odd |=cnt,cnt=0;
				else cnt^=1;
			}
			in_s[i]=has_odd |cnt ? 0:1;
		}
		dp[0][0]=1;
		for(int i = 1;i<=n;i++){
			for(int j = 0;j<1<<m;j++){
				dp[i][j]=0;
				for(int k = 0;k<1<<m;k++){
					if((j&k)==0 && in_s[j|k])dp[i][j]+=dp[i-1][k];
				}
			}
		}
		cout<<dp[n][0]<<endl;
	}
    return 0;
}