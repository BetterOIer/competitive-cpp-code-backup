#include<iostream>
#include<cstring>
#define MAXN 1004
#define refer127 2139062143
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dist[MAXN][MAXN],p[MAXN][MAXN],n,k,q,t;
int main(){
    int t=read();
    for(int i = 1;i<=t;i++){
        memset(p,255,sizeof(p));
        memset(dist,127,sizeof(dist));
        n=read(),k=read(),q=read();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<k;j++){
                dist[i][(k*i+j)%n]=j;
                p[i][(k*i+j)%n]=i;
            }
        }
        /* for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl; */
        for(int i = 0;i<n;i++) dist[i][i]=0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dist[j][i]!=0&&dist[j][i]!=refer127){
                    for(int w = 0;w<n;w++){
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
        for(int i = 1,u,v;i<=q;i++){
            u=read(),v=read();
            if(dist[u][v]==refer127){
                printf("-1\n");
            }else printf("%d\n",dist[u][v]);
        }
    }
}