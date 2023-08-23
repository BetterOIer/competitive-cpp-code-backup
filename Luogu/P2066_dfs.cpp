#include<iostream>
using namespace std;
long long a[20][20],ans=0,ans1=0,n,m,now[21],temp=0,best[21];
void dfs(int k){
    if(k>n){
        if(ans<ans1){
            ans=ans1;
            for(int i = 1;i<=n;i++) best[i]=now[i];
        }
        return;
    }
    for(int i = 0;i<=m;i++){
        now[k]=i;
        temp+=i;
        ans1+=a[k][i];
        if(temp<=m) dfs(k+1);
        ans1-=a[k][i];
        temp-=i;
        now[k]=0;
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dfs(1);
    cout<<ans<<endl;
    for(int i = 1;i<=n;i++){
        cout<<i<<" "<<best[i]<<endl;
    }
    return 0;
}