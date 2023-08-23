#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int ans[1000006],cnt=1;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int N=n>1000?1000:n;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            ans[cnt++]=a[i]+b[j];
        }
    }

}