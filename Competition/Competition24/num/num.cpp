#include<iostream>
#include<cmath>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
long long cnt=0;
long long win=0;
int prim[100010];
bool vis[100010];
long long tot;
void init(){
	for(long long i = 2; i <= 100000; i++){
        if( !vis[i] ){
            prim[++tot] = i;
        }
        for(long long j = 1; j <= tot; j++){
            if(i * prim[j] > 100000) break;
            vis[i * prim[j]] = true;
    	}
    }
}
long long fi(long long n);
long long se(long long n);

long long fi(long long n){
	cnt++;
	int k=0,m=1;
	while(k<2){
		for(int i = 1;i<=tot;i++){
			if(n<=prim[i])goto bre;
			if(n%prim[i]==0){
				n/=prim[i];
				k++;
				m*=prim[i];
				break;
			}
		}
	}
	bre:
	if(!k){
		win=1;
		return m;
	}
	se(m);
	return m;
}
long long se(long long n){
	cnt++;
	int k=0,m=1;
	while(k<2){
		for(int i = 1;i<=tot;i++){
			if(n<=prim[i])goto bre;
			if(n%prim[i]==0){
				n/=prim[i];
				k++;
				m*=prim[i];
				break;
			}
		}
	}
	bre:
	if(!k){
		win=2;
		return m;
	}
	fi(m);
	return m;
}
int main(){
	init();
	long long n=read();
	if(n==1){
		cout<<"1\n0";
		return 0;
	}
	long long ans=fi(n);
	cout<<cnt;
	if(win==1) cout<<"\n"<<ans;
}

