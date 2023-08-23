#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,minn=2147483647,maxn=0;
long long maxans=0,ans=0;
pair<int,int>in[1003],nex;
int findnext(int len,int start){
    for(int i = start;i<=maxn+1-len;i++){
        bool flag=true;
        ans=0;
        for(int j =1;j<=n;j++){
            if(in[j].first<=i&&i+len<=in[j].second){
                ans++;
                continue;
            }
            if(in[j].first>i+len||i>in[j].second) continue;
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            ans=ans*len;
            return i;
        }
    }
    return 0;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        in[i].first=read();
        minn=min(in[i].first,minn);
        in[i].second=read();
        maxn=max(in[i].second,maxn);
    }
    int L=0,R=maxn-minn,sta=0;
    while(L<R){
        int mid=(L+R)>>1;
        sta = findnext(mid,sta+1);
        if(sta==0){
            R=mid-1;
            continue;
        }
        if(maxans>ans){
            R=mid-1;
        }else{
            maxans=ans;
            L=mid+1;
        }
    }
    cout<<maxans;
}