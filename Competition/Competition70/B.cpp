/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#define MAXN 2005
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int dist[MAXN][MAXN],n,m,q;
long long ans=0;
int main(){
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    double cl = clock();
    n=read();
    for(int i = 1;i<=n;i++){
        string s;cin>>s;
        for(int j = 1;j<=n;j++){
            dist[i][j]=(s[j-1]=='1'? 1:n);
        }
    }
    for(int i = 1;i<=n;i++) dist[i][i]=0;
    for(int i = 1;i<=n;i++){
        ans=0;
        for(int j = 1;j<=n;j++){
            for(int w = 1;w<=n;w++){
                if(dist[j][w]>dist[j][i]+dist[i][w]){
                    dist[j][w]=dist[j][i]+dist[i][w];
                }
                w!=j? ans+=1ll*dist[j][w]*dist[j][w]:ans+=0;
            }
        }
        if(clock() - cl > 1.9 * CLOCKS_PER_SEC) {
			break;
		}
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
}