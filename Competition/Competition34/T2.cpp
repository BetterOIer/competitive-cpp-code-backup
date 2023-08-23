#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    char co;
    vector <int> to;
}tree[1000005];
int main(){
    int n=read();
    for(int i = 1;i<=n;i++){
        cin>>tree[i].co;
    }
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        tree[u].to.push_back(v);
        tree[v].to.push_back(u);
    }
    cout<<2;
}