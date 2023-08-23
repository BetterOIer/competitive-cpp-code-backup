#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long f[500005],a[500005],b[500005];
int n,d,k,before,after;
bool check(int g)
{
    before = d-g;
    after = d+g;
    if(before<=0)
        before = 1;
    memset(f,-127,sizeof(f));
    f[0]=0;
    for(int i=1; i<=n; i++)
    {
    	for(int j=i-1; j>=0; j--)
    	{
    		if(a[i]-a[j]<before) continue;
    		if(a[i]-a[j]>after) break;
    		f[i]=max(f[i],f[j]+b[i]);
    		if(f[i]>=k)
    			return 1;
        }
    }
    return 0;
}
int main()
{
    int i,ans=-1,l,r,m;
    cin>>n>>d>>k;
    for(i=1; i<=n; i++) cin>>a[i]>>b[i];
    l=0, r=1005;
    m=(l+r)/2;
    while(l<=r)
    {
        if(check(m)){
            ans=m;r=m-1;
        }
        else l=m+1;
        m=(l+r)/2;
    }
    cout<<ans;
    return 0;
}

