#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct flavour{
    int acid;
    int Bitter;
}a[11];
int n,used[11],aacid=1,bbitter;
long long ans=1000000000000000;
void dfs(int x){
    if(x==n+1)return;
    for(int i = 1;i<=n;i++){
        if(used[i]==0){
            aacid*=a[i].acid;
            bbitter+=a[i].Bitter;
            ans = ans<abs(aacid-bbitter)? ans:abs(aacid-bbitter);
            used[i]=1;
            dfs(x+1);
            used[i]=0;
            aacid/=a[i].acid;
            bbitter-=a[i].Bitter;
        }
    }
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].acid>>a[i].Bitter;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
