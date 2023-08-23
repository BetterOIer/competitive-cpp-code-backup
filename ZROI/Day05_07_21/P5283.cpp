/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
//(4,294,967,295)D=(1111,1111,1111,1111,1111,1111,1111,1111)B
#include<iostream>
#include<queue>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,k,a[500005],len=33,idx,root;
struct node{
    long long size;
    long long ch[2];
}tr[500005*35];
struct RANK{
    long long idx;
    long long rk;
    long long maxn;
};

bool operator < (RANK a,RANK b){return a.maxn<b.maxn;}
bool operator > (RANK a,RANK b){return a.maxn>b.maxn;}

priority_queue<RANK>rks;
void insert(long long pos,long long val){
    for(long long i = len,c;i>=0;i--){
        c=val>>i&1LL;
        tr[pos].size++;
        if(!tr[pos].ch[c])tr[pos].ch[c]=++idx;
        pos=tr[pos].ch[c];
    }
    tr[pos].size++;
}
long long query(long long pos, long long val, long long rank){
    long long ans=0;
    for(long long i = len,c;i>=0;i--){
        c=val>>i&1LL;
        if(!tr[pos].ch[!c])pos=tr[pos].ch[c];
        else{
            if(rank<=tr[tr[pos].ch[!c]].size)pos=tr[pos].ch[!c],ans+=(1LL<<i);
            else rank-=tr[tr[pos].ch[!c]].size,pos=tr[pos].ch[c];
        }
    }
    return ans;
}
int main(){
    n=read(),k=read();
    insert(root,0);
    for(long long i = 1;i<=n;i++){a[i]=read();a[i]^=a[i-1];insert(root,a[i]);}
    for(long long i = 0;i<=n;i++){
        rks.push((RANK){i,1,query(root,a[i],1LL)});
    }
    long long ans=0;
    for(long long i = 1;i<=(k<<1);i++){
        RANK now = rks.top();rks.pop();
        ans+=now.maxn;
        if(now.rk<n)rks.push((RANK){now.idx,now.rk+1LL,query(root,a[now.idx],now.rk+1)});
    }
    cout<<(ans>>1);
    return 0;
}