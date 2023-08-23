#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,m;
string s;
long long f[20][10];
long long gen(long long l,long long r){
    long long res = 0;
    l--,r--;
    for(long long i= l; i <= r; i++)
    res = (res<<1) + (res<<3) + (s[i]^48);
    return res;
}
int main(){
    n=read(),m=read();
    cin>>s;
    for(long long i = 1;i<=n;i++){
        f[i][0]=gen(1,i);
        for(long long j = 1;j<=m;j++){
            for(long long k = 2;k<=i;k++){
                if(k-1>=j-1+1){
                    f[i][j]=max(f[i][j],f[k-1][j-1]*gen(k,i));
                }
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}