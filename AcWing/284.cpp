#include<iostream>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int mod=1000000000;
int S[303];
long long f[303][303];
int n;
int main(){
    string s;
    cin>>s;
    n=s.length();
    if(n%2==0) cout<<0<<endl;
    else{
        for(int len = 1; len<=n; len+=2){
            for(int l = 1;l+len-1<=n;l++){
                int r=l+len-1;
                if(len==1) f[l][r]=1;
                else if(s[l-1]==s[r-1]){
                    for(int k=l;k<r;k+=2) if(s[k-1]==s[r-1]) f[l][r] = (f[l][r] + 1LL*f[l][k]*f[k+1][r-1]%mod)%mod;
                }
            }
        }
        cout<<f[1][n]<<endl;
    }
    return 0;
   /*  for(int i = 0;i<len;i++){
        S[i+1]= s[i]=='A'? 1:0;
    }
    len=s.length();
    if(len%2==0){
        cout<<0;
        return 0;
    }
    for(int i = 1;i<=len;i+=2){
        for(int l = 1;l<=len+1-i;l++){
            int r=l+i-1;
            if(i==1){
                dp[l][r]=1;
                continue;
            }
            if(S[l]!=S[r])continue;
            for(int k = l;k<r;k+=2){
                if(S[k]!=S[r])continue;
                if(dp[l+1][k-1]==-1){
                    cout<<l+1<<" "<<k-1<<endl;
                }
                if(dp[k][r]==-1){
                    cout<<k<<" "<<r<<endl;
                }
                dp[l][r]=(dp[l][r]+1LL*dp[l][k]*dp[k+1][r-1]%mod)%mod;
            }
            //dp[l][r]=(dp[l][r]+dp[l+1][r-1])%mod;
        }
    }
    cout<<dp[1][len];
    return 0; */
}
