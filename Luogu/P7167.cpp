#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define int long long
using namespace std;
const int MAXN = 1e5+10;
const int inf = 2147483647;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int s[MAXN],size;
int f[MAXN][25],u[MAXN][25];
struct node{
    int V;
    int R;
}a[((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((MAXN))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))];
signed main(){
    int n=read(),q=read();
    for(int i = 1;i<=n;i++){
        a[((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((i))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))].R=read();
        a[(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((i)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))].V=read();
    }
    for(int i = n;i>=1;i--){
        while(size&&a[s[size]].R<=a[i].R)	size--;
		f[i][0]=s[size];
		s[++size]=i;
    }
    for(int i=1;i<=23;++i)
		for(int j=1;j<=n;++j)
			f[j][i]=f[f[j][i-1]][i-1];
    for(int i=1;i<=n;++i)	
		u[i][0]=a[f[i][0]].V;
    for(int i=1;i<=n;++i)
		if(f[i][0]==0)	
			u[i][0]=inf;
	for(int i=1;i<=23;++i)
		for(int j=1;j<=n;++j)
			u[j][i]=u[j][i-1]+u[f[j][i-1]][i-1];
    int id,V;
    for(int i = 1;i<=q;i++){
        id=read();
        V=read();
        if(V<=a[id].V){
            cout<<id<<endl;
			continue;
        }
        V-=a[id].V;
		for(int i=23;i>=0;--i)
			if(u[id][i]<=V)	
				V-=u[id][i],id=f[id][i];
		if(V)	id=f[id][0];
		cout<<id<<endl;
    }
    return 0;
}
