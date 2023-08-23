#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,s,u,v;
long long ans=0;
struct node{
    vector <int> son;
    int count=0;
    int val=0;
    int fa=0;
}po[100005];
void dfs(int ro,int step){
    if(step>s) return;
    if(step==s){
        ans++;
        return;
    }
    for(int i:po[ro].son){
        if(i==po[ro].fa)continue;
        else dfs(i,step+po[i].val);
    }
}
int main(){
    n=read(),s=read();
    for(int i = 1;i<=n;i++) po[i].val=read();
    for(int i = 1;i<n;i++){
        u=read(),v=read();
        po[u].son.push_back(v);

        po[v].fa=u;
    }
    for(int i = 1;i<=n;i++)dfs(i,po[i].val);
    cout<<ans;
}