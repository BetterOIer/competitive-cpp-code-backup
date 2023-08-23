#include<bits/stdc++.h>
using namespace std;
int x[5000005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	nth_element(x,x+k,x+n);
	printf("%d",x[k]);
    return 0;
}