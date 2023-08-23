#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1e9+7;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
struct node{
    long long val;
    long long len;
    long long c;
    long long yx;
}pil[100005];
long long n,tot,all_len,ans;
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        pil[i].len=read();
        pil[i].val=read();
        tot+=pil[i].len*pil[i].val;
        all_len+=pil[i].len;
    }
    long long ave=tot/all_len;
    //cout<<ave<<endl;
    for(long long i = 1;i<=n;i++){
        pil[i].c=ave-pil[i].val;
        //cout<<pil[i].c<<" ";
    }
    //cout<<endl;
    /* for(long long i = 1;i<=n;i++){
        ll L=abs((pil[i-1].yx-pil[i].c+pil[i-1].yx-pil[i].len*pil[i].c)),R=pil[i].len;
        //cout<<L<<" "<<R<<endl;
        if(L%2LL==0)L/=2LL;
        else R/=2LL;
        ans=(ans+L%mod*(R%mod)%mod)%mod;
        pil[i].yx=pil[i-1].yx-pil[i].len*pil[i].c;
        //cout<<"js "<<pil[i].js<<"yx "<<pil[i].yx<<endl;
    } */
    for(long long i = 1;i<=n;i++){
        if((pil[i-1].yx-pil[i].c)*(pil[i-1].yx-pil[i].len*pil[i].c)<0){
            int m=abs((pil[i-1].yx-pil[i].c)/pil[i].c),q=abs((pil[i-1].yx-pil[i].len*pil[i].c)/pil[i].c);
            int ma=pil[i-1].yx-pil[i].c-m*pil[i].c,qa;qa=ma-pil[i].c;
            ans=ans+abs(pil[i-1].yx-pil[i].c+ma)*(m+1)/2;
            ans=ans+abs(qa+(pil[i-1].yx-pil[i].len*pil[i].c))*(q+1)/2;
        }else{
            ll L,R=pil[i].len;
            L=abs(pil[i-1].yx-pil[i].c+pil[i-1].yx-pil[i].len*pil[i].c);
            if(L%2LL==0)L/=2LL;
            else R/=2LL;
            ans=(ans+L%mod*(R%mod)%mod)%mod;
        }
        pil[i].yx=pil[i-1].yx-pil[i].len*pil[i].c;
    }
    cout<<ans;
}
