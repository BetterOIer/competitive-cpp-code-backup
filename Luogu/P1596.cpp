#include<iostream>
using namespace std;
int a[101][101],x,y,ans=0;
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
void dfs(int x1,int y1){
    a[y1][x1]=0;
    for(int i = 0;i<=7;i++){
        if(y1+dir[i][0]>0&&y1+dir[i][0]<=y&&x1+dir[i][1]>0&&x1+dir[i][1]<=x&&a[y1+dir[i][0]][x1+dir[i][1]]==1){
            dfs(x1+dir[i][1],y1+dir[i][0]);
        }
    }
}
int main(){
    cin>>y>>x;
    for(int i = 1;i<=y;i++){
        for(int w = 1;w<=x;w++){
            char c;cin>>c;
            if(c=='.') a[i][w]=0;
            else if(c=='W') a[i][w]=1;
        }
    }
    for(int i = 1;i<=y;i++){
        for(int w = 1;w<=x;w++){
            if(a[i][w]==1){
                dfs(w,i);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
