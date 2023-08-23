#include<iostream>
#include<cstring>
using namespace std;
const int N = 60;
int dis[N][N];
bool exist[N][N][N+8];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    memset(exist,false,sizeof(exist));
    memset(dis,10,sizeof(dis));
    for(int i = 1;i<=m;i++){
        cin>>u>>v;
        dis[u][v]=1;
        exist[u][v][0]=1;
    }
    for(int i = 1;i<=64;i++){
        for(int w =1;w<=n;w++){
            for(int j =1;j<=n;j++){
                for(int o = 1;o<=n;o++){
                    if(exist[w][j][i-1]&&exist[j][o][i-1]){
                        exist[w][o][i]=1;
                        dis[w][o]=1;
                    }
                }
            }
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    cout<<dis[1][n];
}
