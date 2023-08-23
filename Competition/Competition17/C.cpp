#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v1,v2;
signed main(){
    int n,h,m,q,qsh,qsm,qeh,qem,eh,mx;
    cin>>n>>h>>m>>q;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld%lld",&qsh,&qsm,&qeh,&qem);
        v1.push_back(qsh*m+qsm);
        v2.push_back(qeh*m+qem);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(q--){
        scanf("%lld%lld",&eh,&mx);
        int pos1=lower_bound(v1.begin(),v1.end(),eh*m+mx)-v1.begin();
        int pos2=lower_bound(v2.begin(),v2.end(),eh*m+mx)-v2.begin();
        if(pos1==pos2) puts("Yes");
        else puts("No");
    }
    return 0;
}