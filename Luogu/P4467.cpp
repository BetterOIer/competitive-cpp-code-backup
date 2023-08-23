#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,k,u,v,w;
struct node{
    int to;
    int val;
};
vector<node>ro[1005];
bool comp(node a,node b){
    return a.val<b.val;
}
struct point{
    int po;
    int len;
    bool operator < (const point w)const{
        return w.len<len;
    }
};
priority_queue<point>P;
int main(){
    n=read(),m=read(),k=read();
    for(int i = 1;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
    }
    for(int i = 1;i<=n;i++){
        sort(ro[i].begin(),ro[i].end(),comp);
    }
    point start;
    start.po=n;
    start.len=0;
    P.push(start);
    while(P.size()&&k){
        point now=P.top();
        P.pop();
        if(now.po==1){
            cout<<now.len<<endl;
            k--;
            continue;
        }
        for(auto i:ro[now.po]){
            P.push((point){i.to,now.len+i.val});
        }
    }
    while(k--){
        cout<<"-1\n";
    }
}