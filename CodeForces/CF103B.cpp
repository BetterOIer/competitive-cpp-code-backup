#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector<int>po[105];
int fa[105];
int find(int x){
    if(x==fa[x])return x;
    else return x=find(fa[x]);
}
int main(){
    int n=read(),m=read();
    if(m!=n){
        cout<<"NO";
        return 0;
    }
    for(int i= 1;i<=n;i++) fa[i]=i;
    for(int i= 1,u,v;i<=m;i++){
        u=read(),v=read();
        po[u].push_back(v);
        po[v].push_back(u);
        fa[find(fa[u])]=find(v);
    }
    for(int i = 1;i<n;i++){
        if(find(fa[i])!=find(fa[i+1])){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"FHTAGN!";
    return 0;
}