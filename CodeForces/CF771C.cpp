//TODO
#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector<int>ro[200005];
int n,k;
int size[200005];
long long ans1,ans2;
int a[200005][7];
int b[200005][7];
void dfs(int pos,int fa){
    size[pos]=a[pos][k-1]=1;
    for(int to:ro[pos]){
        if(to==fa)continue;
        dfs(to,pos);
        size[pos]+=size[to];
        ans
    }
}
int main(){
    n=read(),k=read();
    for(int i = 1,x,y;i<=n;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
    }
    ans1=1LL*n*(n+1)/2*(k-1);
    dfs(1,0);
}

