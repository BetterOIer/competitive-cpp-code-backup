#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10011],b[10011],n2=0,n,ans=0;
int main(){
    freopen("P1090.in","r",stdin);
    freopen("P1090.out","w",stdout);
    cin>>n;
    memset(a,127,sizeof(a));
	memset(b,127,sizeof(b));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0,j=0,w,k;
	for(k=1;k<n;k++){
		w=a[i]<b[j]?a[i++]:b[j++];
		w+=a[i]<b[j]?a[i++]:b[j++];
		b[n2++]=w;
		ans+=w;
	}
	cout<<ans;
 	fclose(stdin);
    fclose(stdout);
    return 0;
} 