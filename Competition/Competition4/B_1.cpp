#include <iostream>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
	int n,l,r,shaoyu=0,dayu=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	cin>>l>>r;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>r) shaoyu+=a[i]-r;
		if(a[i]<l) dayu+=l-a[i];
	} 
	if(sum>n*r) cout<<"-1";
	else cout<<max(shaoyu,dayu);
	return 0;
} 
