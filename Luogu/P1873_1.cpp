#include<iostream>
using namespace std;
long long n,bz,s=0,mid,leftt,longest,trees[1000008];
int main()
{
    scanf("%lld%lld",&n,&bz); 
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&trees[i]);
        longest=max(longest,trees[i]); 
    }
    while(leftt<=longest)
    {
        mid=(leftt+longest)/2; 
        s=0; 
        for(int i=1;i<=n;i++) 
			if(trees[i]>mid) 
				s+=trees[i]-mid;  
        if(s<bz){
            longest=mid-1;
        }
		else 
			leftt=mid+1;
    }
    cout<<leftt-1; 
    return 0;
}
