#include<iostream>
#include<cstring>
using namespace std;
const int N=3e5+5;
const int INF=0x3f3f3f3f;
int n;      
int a[N];
int dist[N];        
bool st[N];     
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], t>j? a[t]-a[j]:a[j]-a[t]);
    }
    return res;
}
int main(){
    freopen("T265204.in","r",stdin);
    freopen("T265204.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    cout<<prim();
    fclose(stdin);
    fclose(stdout);
}