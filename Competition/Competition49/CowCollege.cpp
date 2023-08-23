#include<iostream>
#include<algorithm>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long cost[100005];
long long ans=0,po;
int main(){
    long long n=read();
    for(long long i = 1;i<=n;i++){
        cost[i]=read();
    }
    sort(cost+1,cost+n+1);
    for(long long i = 1;i<=n;i++){
        if(ans<(n+1-i)*cost[i])ans=(n+1-i)*cost[i],po=cost[i];
    }
    cout<<ans<<" "<<po;
}