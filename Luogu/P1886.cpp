#include<iostream>
#include<queue>
using namespace std;
int a[1000005];
long long mi[1000005],ma[1000005],k=0;
long long minn=9223372036854775807,maxn=-9023372036854775807;
queue <int> Q;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i =1;i<=m;i++){
        Q.push(a[i]);
    }
    for(int i = 1;i<=n-m;i++){
        minn=9223372036854775807;
        maxn=-9023372036854775807;
        for(int j = i;j<=i+m;j++){
            minn=min(minn,a[j]);
            maxn=max(maxn,a[j]);
            mi[++k]=minn;
            ma[k]=maxn;
        }
    }
}