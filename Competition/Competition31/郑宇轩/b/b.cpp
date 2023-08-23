#include<iostream>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn=100005;
struct node{
    int po;
    int igo=0;
    int ste=0;
};
queue<node>Q;
pair<int,int> P[maxn];
int better[maxn];
int n,m,k;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    for(int i = 1;i<=maxn;i++) better[i]=2147483647;
    n=read(),m=read(),k=read();
    for(int i = 1;i<=m;i++){
        P[i].first=read();
        P[i].second=read();
    }
    node start;
    start.po=k;
    start.ste=0;
    start.igo=0;
    Q.push(start);
    while(Q.size()){
        node now=Q.front();Q.pop();
        if(now.ste==m){
            better[now.po]=min(better[now.po],now.igo);
            continue;
        }
        if(P[now.ste+1].first!=now.po&&P[now.ste+1].second!=now.po){
            node nex;
            nex.po=now.po;
            nex.igo=now.igo;
            nex.ste=now.ste+1;
            Q.push(nex);
            continue;
        }
        node nex;
        nex.po=(P[now.ste+1].first==now.po? P[now.ste+1].second:P[now.ste+1].first);
        nex.igo=now.igo;
        nex.ste=now.ste+1;
        Q.push(nex);
        nex.po=now.po;
        nex.igo=now.igo+1;
        nex.ste=now.ste+1;
        Q.push(nex);
    }
    for(int i = 1;i<=n;i++){
        if(better[i]==2147483647)cout<<"-1 ";
        else cout<<better[i]<<" ";
    }
}