#include<iostream>
#include<cstring>
#define MAXN 200005
using namespace std;
int n,m,wei[MAXN],val[MAXN],l[MAXN],r[MAXN],mx=0,mn=2147483647;
long long pre_n[MAXN],pre_v[MAXN];
long long Y,s,sum;
bool check(int W){
    Y=0,sum=0;
    memset(pre_n,0,sizeof(pre_n));
	memset(pre_v,0,sizeof(pre_v));
    for(int i = 1;i<=n;i++){
        if(wei[i]>=W) pre_n[i]=pre_n[i-1]+1,pre_v[i]=pre_v[i-1]+val[i];
        else pre_n[i] = pre_n[i-1],pre_v[i] = pre_v[i-1];
    }
    for(int i = 1;i<=m;i++){
        Y+=(pre_n[r[i]]-pre_n[l[i]-1])*(pre_v[r[i]]-pre_v[l[i]-1]);
    }
    sum = abs(Y-s);
    if(Y>s)return true;
    else return false;
}
int main(){
    cin>>n>>m>>s;
    for(int i = 1;i<=n;i++){
        cin>>wei[i]>>val[i];
        mx=max(mx,wei[i]);
		mn=min(mn,wei[i]);
    }
    for(int i = 1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    int left=mn-1,right=mx+2,mid;
    long long ans=9223372036854775807;
    while(left<=right){
        mid=(left+right)>>1;
        if(check(mid)) left=mid+1;
        else right = mid-1;
        if(sum<ans) ans=sum;
    }
    cout<<ans;
}