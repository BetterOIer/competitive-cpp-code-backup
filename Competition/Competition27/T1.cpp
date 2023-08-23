#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int a[5050];
long long ans;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long all=(1<<n)-1;
    for(long long i = 1;i<=all;i++){
        long long now=i,gs=0;
        deque<int>pp;
        while(now){
            int po=now-(now&(now-1));
            now&=(now-1);
            gs++;
            int p=log2(po);
            pp.push_back(p+1);
        }
        if(gs<3)continue;
        else{
            long long p1=pp.front(),p2=pp.back(),p3;
            pp.pop_front();
            p3=pp.front();
            if(a[p1]+a[p3]>a[p2]){
                ans++;
            }
        }
    }
    cout<<ans%998244353;
}