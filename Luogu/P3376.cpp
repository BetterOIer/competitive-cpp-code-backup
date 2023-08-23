#include<vector>
#include<iostream>
using namespace std;
struct node{
    int to;
    int cap;
    int flow=0;
};
vector<node> ro[505];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}

long long n,m,s,t;
int main(){
    int u,v,w;
    n=read(),m=read(),s=read(),t=read();
    for(int i = 1;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back(node{v,w});
    }
    long long SMAX=EK(s,t);
}