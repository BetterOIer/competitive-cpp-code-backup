#include<iostream>
using namespace std;
int a[110][110];
int main(){
    int n,m,ans=0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 2;i<=n;i++){
        for(int j = 2;j<=m;j++){
            if(a[i][j]&&a[i-1][j]&&a[i-1][j-1]&&a[i][j-1]){
                a[i][j]+=min(min(a[i][j-1],a[i-1][j]),a[i-1][j-1]);
            }
            ans=max(ans,a[i][j]);
        }
    }
    cout<<ans;
    return 0;
}