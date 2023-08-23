#include<iostream>
#define MAXN 1005
using namespace std;
int n,m,dt[MAXN][MAXN],ans[MAXN][MAXN];
int main(){
    int yl,xl,yr,xr;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>yl>>xl>>yr>>xr;
        for(int j = yl;j<=yr;j++){
            dt[j][xl]++;
            dt[j][xr+1]--;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            ans[i][j]=ans[i][j-1]+dt[i][j];
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}