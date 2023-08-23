#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int L,n,k;
int MoS2(int mid)
{
    int m=0;
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]>=mid)
        {
            m+=(a[i]-a[i-1])/mid;
            if((a[i]-a[i-1])%mid==0) m--;
        }
    if(m>k) return 0;
    else return 1;
}
int main(){
    cin>>L>>n>>k;;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=0,r=L;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(MoS2(mid)==1) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}
