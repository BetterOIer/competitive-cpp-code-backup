#include<iostream>
using namespace std;
string s;
int dp[5001][5001];
bool is_pal[5001][5001];
inline int read() {
    int x=0,f=0;
    char ch=getchar();
    while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
int main(){
    cin>>s;
    int n=s.length();
    for(int len=1;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(s[i]!=s[j]) continue;
            if(i>=j-1||is_pal[i+1][j-1]) is_pal[i][j]=true;
        }
    }
    for(int i = 0;i<n;i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+is_pal[i][j];
        }
    }
    int t,l,r;
    t=read();
    while(t--){
        l=read(),r=read();
        printf("%d\n",dp[l-1][r-1]);
    }
}