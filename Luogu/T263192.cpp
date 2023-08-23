#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    int T,n,m,chosex,chosey;
    long double ans=0,as=0,p,q;
    T=read();
    T=read();
    for(;T--;){
        cin>>n>>m;
        ans=0;
        for(int i = 1;i<=n;i+=2){
            for(int j = 1;j<=m;j+=2){
                chosey=max(i-1,n-i);
                chosex=max(j-1,m-j);
                ans+=sqrt(chosey*chosey+chosex*chosex);
            }
        }
        if(n%2==1){
			q=n/2+1;
		}
		else{
			q=n/2;
		}
		if(m%2==1){
			p=m/2+1;
		}
		else{
			p=m/2;
		}
		as=q*p;
        printf("%d %.8Lf\n",n*m-(int)as,ans);
    }
}