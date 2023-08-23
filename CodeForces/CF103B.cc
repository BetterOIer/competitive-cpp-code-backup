#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=102,M=5001;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int fa[N];
inline int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
    	int u=read(),v=read();
    	fa[find(u)]=find(find(v));
	}
	if(n>m)return puts("NO"),0;
	for(int i=2;i<=n;i++){
		if(find(i)!=find(i-1))return puts("NO"),0;
	}
	return puts("FHTAGN!"),0;
}