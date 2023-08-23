/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
inline void write(long long x){if(x<0) putchar('-'),x=-x;if(x>9) write(x/10);putchar(x%10+'0');}
long long tr[6000005];
void pushup(long long pos){
    tr[pos] = min(tr[pos<<1],tr[pos<<1|1]);
}
void build(long long pos,long long l,long long r){
    if(l == r){
        tr[pos]=read();
        return;
    }
    long long mid = (l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
long long query_area(long long pos,long long l,long long r,long long x,long long y){
    if(x<=l&&r<=y){
        return tr[pos];
    }
    long long mid = (l+r)>>1;
    long long ans = 9223372036854775807ll;
    if(mid>=x)ans = min(ans,query_area(pos<<1,l,mid,x,y));
    if(mid<y)ans = min(ans,query_area(pos<<1|1,mid+1,r,x,y));
    return ans;
}
int main(){
    long long n=read(),m=read();
    build(1,1,n);
    write(0);
    for(long long i = 2;i<=n;i++){
        puts("");
        write(query_area(1,1,n,max(i-m,1ll),i-1));
    }
    return 0;
}