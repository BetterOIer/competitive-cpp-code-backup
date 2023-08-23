/*=================================================
* Le vent se lève,il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,k;
vector<int>a,b,nums1,nums2;
int main(){
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
	n=read(),k=read();
	if(k == 0){
		cout<<"1";
		return 0;
	}
	for(int i=0;i<(1<<(k+k-1));i++) if(__builtin_popcount(i) == k) nums1.push_back(i);
	for(int i=1<<(k+k-1);i<(1<<(k+k));i++) if(__builtin_popcount(i) == k) nums2.push_back(i);
	a.resize(1<<(k+k),0),b.resize(1<<(k+k),0),a[((1<<k)-1)<<k]=1;
	for(int i=1;i <= n;i++){
		b.swap(a),a.clear(),a.resize(1<<(k+k),0);
		for(int j:nums1) a[j<<1]=b[j];
		for(int j:nums2){
			int l=(j<<1)&((1<<(k+k))-1);
			for(int x=1<<(k+k-1);x > 0;x>>=1) if(!(l&x)) a[l^x]=(a[l^x]+b[j])%mod;
		}
	}
	cout<<a[((1<<k)-1)<<k];
    fclose(stdin);
    fclose(stdout);
	return 0;
}