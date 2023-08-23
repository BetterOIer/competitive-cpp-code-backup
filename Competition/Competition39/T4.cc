#include<bits/stdc++.h>
using namespace std;
__int128 a[200010];
const long long maxans=1073741824;
void print(__int128 x){
	if (!x) return ;
	if (x < 0) putchar('-'),x = -x;
	print(x / 10);
	putchar(x % 10 + '0');
}
inline __int128 read(){
	__int128 x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
	__int128 n,q;
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	while(q--){
		__int128 fir;
		fir=read();
		if(fir==1){__int128 u,v;u=read(),v=read();a[u]=v;}
		if(fir==2){
			bool ToLar=0;
			__int128 l,r,ans=1;
			l=read(),r=read();
			if(r-l>60){printf("Too large\n");continue;}
			__int128 sum=0;
			for(int i=l;i<=r;i++) if(a[i]<0)sum++;
			if(sum%2==0){
				for(int i=l;i<=r;i++){
					ans*=a[i];
					if(ans>maxans){ToLar=1;break;}
				}
			}else{
				bool flag=0;
				for(int i=l;i<=r;i++){
					if(flag==1){ans*=a[i];if(ans>maxans){ToLar=1;break;}}
					if(a[i]<0)flag=1;
				}
				__int128 ans2=1;flag=0;
				for(int i=r;i>=l;i--){
					if(flag==1){ans2*=a[i];if(ans>maxans){ToLar=1;break;}}
					if(a[i]<0)flag=1;
                }
				ans=max(ans,ans2);
			}
			if(ans>maxans||ans<=0||ToLar==1){
				printf("Too large\n");
			}else{
				print(ans);
				printf("\n");
			}
		}
	}
	return 0;
}