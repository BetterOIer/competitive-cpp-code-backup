#include<iostream>
using namespace std;
int n,k,p,flag,ans,np,sum[50],c[200005];
int main()
{
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>np;
		if(np<=p){
			for(int j=i;j>flag;j--){
                sum[c[j]]++;
            }
			flag=i,ans+=sum[c[i]]-1;
		}
		else ans+=sum[c[i]];
	}
	cout<<ans;
	return 0;
}