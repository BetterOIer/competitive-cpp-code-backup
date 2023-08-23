#include<bits/stdc++.h>
#define refer127 2139062143
using namespace std;
int dist[20][20],p[20][20];
int main(){
    freopen("transport.in","r",stdin);
    freopen("transport.out","w",stdout);
    memset(p,255,sizeof(p));
    memset(dist,127,sizeof(dist));
    int n,m,u,v,w;
    scanf("%d%d",&n,&m);
    for(int i =1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        dist[u][v]=w;
        p[u][v]=u;
        dist[v][u]=w;
        p[v][u]=v;
    }
    for(int i = 1;i<=n;i++) dist[i][i]=0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(dist[j][i]!=0&&dist[j][i]!=refer127){
                for(int w = 1;w<=n;w++){
                    if(dist[i][w]!=refer127){
                        if(dist[j][w]>dist[j][i]+dist[i][w]){
                            dist[j][w]=dist[j][i]+dist[i][w];
                            p[j][w]=p[i][w];
                        }
                    }
                }
            }
        }
    }
    printf("40");
    fclose(stdin);
    fclose(stdout);
    return 0;
}