/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
const long long mod = 1000000007LL;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long ys=2;
long long Ans=1;
long long dp[65][10005];
//long long inv[66]={0, 1, 500000004, 333333336, 250000002, 400000003, 166666668, 142857144, 125000001, 111111112, 700000005, 818181824, 83333334, 153846155, 71428572, 466666670, 562500004, 352941179, 55555556, 157894738, 850000006, 47619048, 409090912, 739130440, 41666667, 280000002, 576923081, 370370373, 35714286, 758620695, 233333335, 129032259, 281250002, 939393946, 676470593, 628571433, 27777778, 621621626, 78947369, 717948723, 425000003, 658536590, 23809524, 395348840, 204545456, 822222228, 369565220, 404255322, 520833337, 448979595, 140000001, 784313731, 788461544, 56603774, 685185190, 763636369, 17857143, 385964915, 879310351, 50847458, 616666671, 688524595, 564516133, 15873016, 140625001, 30769231};
inline long long power(long long a,long long t){
	long long res = 1;
	while(t){
		if(t&1) res = res*a%mod;
		a = a*a%mod;
		t >>= 1;
	}
	return res;
}

long long inv(long long n){
	return power(n,1000000005);
}

long long dfs(long long tim,long long k){
    if(!tim) return dp[tim][k]=1;
    if(!k){
        if(!dp[tim][k]) dp[tim][k]=dfs(tim-1,k)*ys%mod;
        return dp[tim][k];
    }
    long long ans=0;
    for(long long i= 0;i<=tim;i++){
        if(!dp[i][k-1]) dp[i][k-1] = dfs(i,k-1);
        (ans+=dp[i][k-1])%=mod;
    }
    return dp[tim][k] = ans*inv(tim+1)%mod;
}
int main(){
    long long n=read(),k=read();
    while(ys*ys<=n){//直接判断的话,可能有一个大于sqrt n的因数，导致很慢
        if(n%ys!=0){ys++;continue;}
        long long tim=0;
        while(n%ys==0){
            tim++;
            n/=ys;
        }
        memset(dp,0,sizeof dp);
        (Ans*=dfs(tim,k))%=mod;
    }
    memset(dp,0,sizeof dp);
    ys=n;
	if(ys>1) (Ans*=dfs(1,k))%=mod;//n此时可能大于0,再做一次
    cout<<Ans;
    return 0;
}