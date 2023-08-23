#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn=705;
const int mod=1e9+7;
int n,Braket[maxn];
long long dp[maxn][maxn][3][3];
char s[maxn];
stack <int> Br;
void dfs(int l,int r){
	if(l+1==r) dp[l][r][0][1]=dp[l][r][0][2]=dp[l][r][1][0]=dp[l][r][2][0]=1;
	else if(Braket[l]==r){
		dfs(l+1,r-1);
		for(int i=0;i<=2;i++){
			for(int j=0;j<=2;j++){
		        if(j!=1) dp[l][r][0][1]=(dp[l][r][0][1]+dp[l+1][r-1][i][j])%mod;
		        if(j!=2) dp[l][r][0][2]=(dp[l][r][0][2]+dp[l+1][r-1][i][j])%mod;
		        if(i!=1) dp[l][r][1][0]=(dp[l][r][1][0]+dp[l+1][r-1][i][j])%mod;
		        if(i!=2) dp[l][r][2][0]=(dp[l][r][2][0]+dp[l+1][r-1][i][j])%mod;
			}
        }
	}
	else{
		dfs(l,Braket[l]),dfs(Braket[l]+1,r);
		for(int i=0;i<=2;i++){
			for(int j=0;j<=2;j++){
				for(int p=0;p<=2;p++){
					for(int q=0;q<=2;q++){
						if((j==1&&p==1)||(j==2&&p==2)) continue;
						dp[l][r][i][q]=(dp[l][r][i][q]+dp[l][Braket[l]][i][j]*dp[Braket[l]+1][r][p][q]%mod)%mod;
					}
                }
            }
        }
	}
}

int main(){
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]=='(') Br.push(i);
		else Braket[Br.top()]=i,Braket[i]=Br.top(),Br.pop();
	}
	dfs(0,n-1);
	long long ans=0;
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			ans=(ans+dp[0][n-1][i][j])%mod;
        }
    }
	printf("%lld\n",ans);
	return 0;
}
