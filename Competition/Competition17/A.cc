#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e7+7;
ll t,n,x,ans;
priority_queue<ll,vector<ll>,less<ll> > heap;
int main(){
    scanf("%d",&t);
    while(t--){
        while(!heap.empty()) heap.pop();
        ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            heap.push(x);
        }
        while(1){
            ll xx=heap.top();
            heap.pop();
            ll yy=heap.top();
            heap.pop();
            if(xx+yy<=0) break;
            ans=(ans+xx+yy)%mod;
            heap.push(xx+yy);
            if(heap.size()==1){
                heap.pop();
                break;
            }
        }
        if(ans<=0) printf("0\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
