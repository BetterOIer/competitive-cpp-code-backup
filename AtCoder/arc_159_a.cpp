/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 105
#define refer127 2139062143
int dist[MAXN][MAXN],p[MAXN][MAXN],n,q;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int main(){
    memset(p,255,sizeof(p));
    memset(dist,127,sizeof(dist));
    int u,v;
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dist[u][v]=read();
            p[u][v]=u;
        }
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
    for(int i = 1;i<=q;i++){
        scanf("%d%d",&u,&v);
        if(dist[u][v]==refer127){
            printf("-1\n");
        }else printf("%d\n",dist[u][v]);
    }
    return 0;
}