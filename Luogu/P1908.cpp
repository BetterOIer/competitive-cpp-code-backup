#include<cstdio>
#include<iostream>
#define I using 
#define AK namespace 
#define IOI std 
I AK IOI;
int n,a[500010],c[500010];
long long ans;

void nssb_sort(int b,int e)
{
    if(b==e)  
		return;
    int mid=(b+e)/2,i=b,j=mid+1,k=b;
    nssb_sort(b,mid),nssb_sort(mid+1,e);
    while(i<=mid&&j<=e)
    	if(a[i]<=a[j])
    		c[k++]=a[i++];
    	else
    		c[k++]=a[j++],ans+=mid-i+1;
    while(i<=mid)
    	c[k++]=a[i++];
    while(j<=e)
    	c[k++]=a[j++];
    for(int l=b;l<=e;l++)
    	a[l]=c[l];
} 

int main()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    nssb_sort(1,n);
    printf("%lld",ans);
    return 0;
}
