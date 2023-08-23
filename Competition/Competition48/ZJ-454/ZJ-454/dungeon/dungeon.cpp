#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long cir[100006],n;
long long MA=9223372036854775807ll;
void dfs(int p1,int p2,long long ma,long long now){
    if(p2-p1>n){
        MA=min(MA,ma);
        return;
    }
    if(ma>MA)return;
    dfs(p1-1,p2,max(ma,-(now+cir[p1])),now+cir[p1]);
    dfs(p1,p2+1,max(ma,-(now+cir[p2])),now+cir[p2]);
}
int main(){
    freopen("dungeon.in","r",stdin);
    freopen("dungeon.out","w",stdout);
    long long T=read();
    while(T--){
        n=read();
        MA=9223372036854775807ll;
        for(long long i = 1;i<=n;i++){
            cir[i]=cir[i+n]=read();
        }
        dfs(n,n+2,max(0LL,-cir[1+n]),cir[1+n]);
        cout<<MA<<endl;
    }
    return 0;
}