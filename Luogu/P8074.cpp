#include<iostream>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int x;
    int y;
    int z;
}planet[100005];
struct Qnode{
    int from;
    int to;
    int val;
    bool operator < (const Qnode &w)const{
        return w.val<val;
    }
};
int n;
priority_queue<Qnode>Q;
bool in[100006];
long long ans=0;
void K(){
    Qnode cnt,nex;
    cnt.from=1;
    for(int i = 2;i<=n;i++){
        cnt.to=i;
        cnt.val=min(abs(planet[i].x-planet[1].x),min(abs(planet[i].y-planet[1].y),abs(planet[i].z-planet[1].z)));
        Q.push(cnt);
    }
    in[1]=true;
    while(Q.size()){
        cnt=Q.top();Q.pop();
        if(in[cnt.to])continue;
        in[cnt.to]=true;
        ans+=cnt.val;
        for(int i = 1;i<=n;i++){
            if(in[i])continue;
            nex.to=i;
            nex.from=cnt.to;
            nex.val=min(abs(planet[i].x-planet[cnt.to].x),min(abs(planet[i].y-planet[cnt.to].y),abs(planet[i].z-planet[cnt.to].z)));
            Q.push(nex);
        }
    }
}
int main(){
    n=read();
    for(int _ = 1;_<=n;_++){
        planet[_].x=read(),planet[_].y=read(),planet[_].z=read();
    }
    
    K();
    cout<<ans;
}