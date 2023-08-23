#include<iostream>
#include<queue>
#define ll long long
using namespace std;
struct node{
    ll v,d;
    node(){v=0,d=0;}
    node(ll v,ll d):v(v),d(d){}
    bool operator <(const node &a)const{
        return a.v==v? d>a.d : v>a.v;
    }
};
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void write(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
ll ans;
priority_queue<node>Q;
int main(){
    ll n=read(),k=read(),o;
    for(int i=1;i<=n;i++){
        o=read();
        Q.push(node(o,1));
    }
    while((Q.size()-1)%(k-1)!=0)Q.push(node(0,1));//?
    while(Q.size()>=k){
        ll d = -1,v=0;
        for(int i=1;i<=k;++i){
            node now=Q.top();Q.pop();
            d=max(d,now.d);
            v+=now.v;
        }
        ans+=v;
        Q.push(node(v,d+1));
    }
    write(ans);
    puts("");
    write(Q.top().d-1);
}