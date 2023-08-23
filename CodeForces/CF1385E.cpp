#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int t,n,m;
vector<int>to[200005];
struct Edge{
    int from;
    int to;
};
vector<Edge>edge;
int ru[200005];
queue<int>Q;
int topo[200005],tot=0;
bool toposort(){
    for(int i = 1;i<=n;i++){
        if(!ru[i]){
            Q.push(i);
            topo[i]=++tot;
        }
    }
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        for(int i:to[now]){
            ru[i]--;
            if(!ru[i]){
                Q.push(i);
                topo[i]=++tot;
            }
        }
    }
    if(tot<n) return false;
    else return true;
}
int main(){
    t=read();
    while(t--){
        n=read(),m=read();
        for(int i= 1,u,v,o;i<=m;i++){
            o=read(),u=read(),v=read();
            if(o){
                to[u].push_back(v);
                ++ru[v];
            }
            else edge.push_back((Edge){u,v});
        }
        if(toposort()){
            cout<<"YES\n";
            for(int i = 1;i<=n;i++){
                for(int j:to[i]){
                    cout<<i<<" "<<j<<endl;
                }
            }
            for(Edge i:edge){
                if(topo[i.from]<topo[i.to]){
                    cout<<i.from<<" "<<i.to<<endl;
                }else{
                    cout<<i.to<<" "<<i.from<<endl;
                }
            }
        }else cout<<"NO\n";
        tot=0;
        edge.clear();
        for(int i = 1;i<=n;i++)to[i].clear();
        for(int i = 1;i<=n;i++)ru[i]=0;
        cout<<endl;
    }
}