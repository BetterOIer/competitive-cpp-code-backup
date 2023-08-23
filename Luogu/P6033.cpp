#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int N=1e7+100;
const int M=1e5+100;
long long ans;int n;
int a[N],cnt[M];
queue<long long> q1,q2;
inline long long Gtop(){
	if (q2.empty()||(!q1.empty()&&q1.front()<q2.front())){
        long long x=q1.front();
        q1.pop();
        return x;
    }
	else{
        long long x=q2.front();
        q2.pop();
        return x;
    }
}
int main(){
	memset(cnt,0,sizeof(cnt));
	n=read();ans=0ll;
	for(int i=1;i<=n;i++){
        a[i]=read();
		cnt[a[i]]++;
    }
	for(int i=1;i<=100000;i++){
		for(int j=1;j<=cnt[i];j++){
			q1.push(i);
        }
    }
	for(register int i=1;i<n;i++){
		long long x=Gtop();
		long long y=Gtop();
		ans+=x+y;q2.push(x+y);
	}
	printf("%lld",ans);
	return 0;
}