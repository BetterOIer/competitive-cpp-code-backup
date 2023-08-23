/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long k,l,r;
long long maxn=1458;
long long table[10]={0,1,4,9,16,25,36,49,64,81};
long long cal(__int128 whi){
	long long ans=0;
	while(whi){
		long long now = whi%10;
		ans+=table[now];
		whi/=10;
	}
	return ans;
}
int main(){
    freopen("standard.in","r",stdin);
    freopen("standard.out","w",stdout);
	long long t=read();
	while(t--){
		long long ans=0;
		k=read(),l=read(),r=read();
		for(long long i = 0;i<=maxn;i++){
			if(i==cal((__int128)(i)*k)&&(__int128)(i)*k>=l&&(__int128)(i)*k<=r){
				++ans;
			}
		}
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}