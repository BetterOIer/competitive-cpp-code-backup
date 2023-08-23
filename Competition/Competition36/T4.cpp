#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int s,t,n,m;
struct node{
    int to;
    long long val;
};
vector<node> po[100005];
queue<int> Q;
int ru[100005],pre[100005];
long long dis[100005];
void print(long long x){
    if(pre[x]==x){cout<<x<<" ";return ;}
    else{print(pre[x]);cout<<x<<" ";}
}
int main(){
    s=read(),t=read(),n=read(),m=read();
    for(int i = 1;i<=n;i++) dis[i]=-1,pre[i]=i;
    long long w;
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read(),w=read();
        po[u].push_back((node){v,w});
        ru[v]++;
    }
    for(int i=1;i<=n;i++)dis[i]=-114514;
    dis[s]=0;
    for(int i=1;i<=n;i++)if(!ru[i])Q.push(i);
    while(Q.size()){
        int now=Q.front();Q.pop();
        for(node i:po[now]){
            if(dis[now]+i.val>dis[i.to]){
                dis[i.to]=dis[now]+i.val;
                pre[i.to]=now;
            }//else if(dis[now]+i.val==dis[i.to])if(pre[i.to]>now)pre[i.to]=now;
            ru[i.to]--;
			if(!ru[i.to])Q.push(i.to);
        }
    }
    cout<<dis[t]<<endl;
    print(t);
}