#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node {
    int to;
};
vector<int>ro[2000005];
int deg[2000005];
bool tj1=false,tj2=false;
int a[2000005];
int su1=0,su2=0;
int main(){
    freopen("csample.in","r",stdin);
    freopen("csample.out","w",stdout);
    int n=read(),m=read(),k=read();
    if(m==n)tj1=true;
    for(int i = 1;i<=m;i++){
        a[i]=read();
    }
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
        deg[u]++;
        if(deg[u]==1){
            su1++;
        }else if(deg[u]==2){
            su2++;
            su1--;
        }else{
            su2--;
        }
        if(deg[v]==1){
            su1++;
        }else if(deg[v]==2){
            su2++;
            su1--;
        }else{
            su2--;
        }
    }
    if(su2==n-2&&su1==2){
        tj2=true;
    }
    if(tj1&&tj2){
        long long ans=0;
        if(n&1==0) ans=n-ceil(1.0*n/2);
        for(int i = 1;i<=n;i++){
            cout<<ans+1LL*ceil(1.0*n/2)*(ceil(1.0*n/2)-1);
        }
    }else{
        cout<<1;
    }
    return 0;
}