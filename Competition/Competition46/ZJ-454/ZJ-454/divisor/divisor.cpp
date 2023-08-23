#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long leng[10000],tot=0,n,m,nm;
long long ans=0;
void dfs(int step,long long an){
    if(step>=2*m){
        if(nm>=an){
            ans=(ans+1)%998244353;
        }
        return;
    }
    for(int i = 1;i<=tot;i++){
        dfs(step+1,an*leng[i]);
    }
}
int main(){
    freopen("divisor.in","r",stdin);
    freopen("divisor.out","w",stdout);
    n=read(),m=read();
    nm=pow(n,m);
    int t=sqrt(n);
    for(int i = 1;i<=t;i++){
        if(n%i==0){
            leng[++tot]=i;
            leng[++tot]=n/i;
            if(i==n/i)tot--;
        }
    }
    sort(leng+1,leng+tot+1);
    dfs(0,1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}