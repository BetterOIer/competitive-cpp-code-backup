/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 1e8-3;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
struct node{
    int val;
    int idx;
}a[100005],b[100005];
int c[100005],p[100005],ans;
bool operator < (node a,node b){return a.val<b.val;}
bool operator > (node a,node b){return a.val>b.val;}
void merge_sort(int l,int r){
    if(l>=r)return;
    int mid =(l+r)>>1;
    int i=l,j=mid+1,k=l;
    merge_sort(l,mid),merge_sort(mid+1,r);
    while(i<=mid&&j<=r){
        if(c[i]>c[j])p[k++]=c[j++],ans=(ans+mid-i+1)%mod;
        else p[k++]=c[i++];
    }
    while(i<=mid)p[k++]=c[i++];
    while(j<=r)p[k++]=c[j++];
    for(i=l;i<=r;i++)c[i]=p[i];
    return;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        a[i].val=read();
        a[i].idx=i;
    }
    for(int i = 1;i<=n;i++){
        b[i].val=read();
        b[i].idx=i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        c[a[i].idx]=b[i].idx;
    }
    merge_sort(1,n);
    cout<<ans;
    return 0;
}