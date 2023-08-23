#include<iostream>
#include<queue>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long cir[100006];
int n;
struct node{
    int p1;
    int p2;
    long long ma;
    long long now;
    bool operator < (const node &w)const{
        return w.ma<ma;
    }
};
priority_queue<node>Q;
int main(){
    freopen("dungeon3.in","r",stdin);
    freopen("dungeon.out","w",stdout);
    long long T=read();
    while(T--){
        n=read();
        for(long long i = 1;i<=n;i++) cir[i]=cir[i+n]=read();
        Q.push((node){n,n+2,max(0LL,-cir[1+n]),cir[1+n]});
        while(Q.size()){
            node now=Q.top();Q.pop();
            if(now.p2-now.p1>n){
                cout<<now.ma<<endl;
                while(Q.size())Q.pop();
                break;
            }
            if(now.p2-now.p1<=n){
                Q.push((node){now.p1-1,now.p2,max(now.ma,-(now.now+cir[now.p1])),now.now+cir[now.p1]});
                Q.push((node){now.p1,now.p2+1,max(now.ma,-(now.now+cir[now.p2])),now.now+cir[now.p2]});
            }
        }
    }
    return 0;
}