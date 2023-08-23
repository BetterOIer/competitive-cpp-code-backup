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
int n,m,k,sta,en;
struct node{
    int to;
    int val;
};
struct Qnode{
    int po;
    int val;
};
vector<node> ro[1005];
queue<Qnode> Q;
int maxdis=2147483647;
int main(){
    n=read(),m=read(),k=read(),sta=read(),en=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
    }
    Q.push((Qnode){sta,0});
    while(Q.size()){
        Qnode now=Q.front();Q.pop();
        if(now.po==en){
            if(now.val<maxdis&&now.val%k==0){
                maxdis=now.val;
            }
        }
        for(node i:ro[now.po]){
            if(now.val+i.val<maxdis){
                Q.push((Qnode){i.to,now.val+i.val});
            }
        }
    }
    if(maxdis==2147483647)cout<<-1;
    else cout<<maxdis;
}