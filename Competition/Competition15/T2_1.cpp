#include<iostream>
#include<queue>
#define maxn 10//?
using namespace std;
const int mod=1e9+7;
int a[maxn],b[maxn],c[maxn],d[maxn];
deque <int> Q1,Q2;
long long ans=1;
int main(){
    int n,k;
    cin>>n>>k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i]=b[i-1]+a[i];
        while (Q1.size() && Q1.front() < i - k + 1) Q1.pop_front();
        while (Q1.size() && a[Q1.back()] > a[i]) Q1.pop_back();
        Q1.push_back(i);
        if (i >= k) d[i]=a[Q1.front()];
    }//min
    for (int i = 1; i <= n; i++) {
        while (Q2.size() && Q2.front() < i - k + 1) Q2.pop_front();
        while (Q2.size() && a[Q2.back()] < a[i]) Q2.pop_back();
        Q2.push_back(i);
        if (i >= k) c[i]=a[Q2.front()];
    }//max
    for(int i = k;i<=n;i++){
        long long now = b[i]-b[i-k]-c[i]-d[i];
        ans=ans*now%mod;
    }
    cout<<ans;
}