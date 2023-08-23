#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
long long ans,num;
long long a[MAXN],b[MAXN],c[MAXN],n,m,p; 
bool flag;
int main(){
	scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
    	a[i]=i;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	
	for(int i=1;i<=ans;i++){
		flag=0;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int k=1;k<=m;k++){
		    for(int j=1;j<=n;j++){
			    c[j]=b[b[j]];
		    }
		    for(int j=1;j<=n;j++){
		    	b[j]=c[j];
			}
	    }
		for(int j=1;j<=n;j++){
			if(b[j]!=j){
				flag=1;
				break;
			}
		}
		
		if(!flag){
			num++;
		}
		//num%=p;
	    next_permutation(a+1,a+1+n); 
	}
	printf("%lld",num);
	return 0;
}
