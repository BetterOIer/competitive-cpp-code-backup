#include<cstdio> 
#include<algorithm>
#include<cstring>
#define ll long long
#define N 2003
#define p 1000000007
using namespace std;

int po(int chengshu,int t){
    int ans = 1;
    while(t){
        if(t&1) ans=(ll)ans*chengshu%p;
        chengshu=(ll)chengshu*chengshu%p;
        t/=2;
    }
    return ans;
}

int n,ans,dec,jishu;
char a[N];
int ANS[N],jsgs[N],cnt[26];

int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    jsgs[0] = 1;
    jsgs[1] = 1;
    ANS[0] = 1;
    ANS[1] = 1;
    for( int i=2;i<=n;++i) jsgs[i] = ANS[i] = (ll)ANS[i-1]*i%p;
    jsgs[n] = po(ANS[n],p-2);
    for( int i=n-1;i>1;--i) jsgs[i] = (ll)jsgs[i+1]*(i+1)%p;
    for( int i=1;i<=n;++i) ++cnt[a[i]-'a'];
    for( int i=0;i<26;++i) jishu += cnt[i]&1;
    if(jishu>1){
        printf("%d",ANS[n]);
        return 0;
    }
    jishu = 1;
    for( int i=0;i<26;++i)
        if(cnt[i]&1) jishu = cnt[i];
    dec = (ll)ANS[n>>1]*jishu%p;
    for( int i=0;i<26;++i) cnt[i] >>= 1;
    for( int i=0;i<26;++i) dec = (ll)dec*ANS[cnt[i]<<1]%p*jsgs[cnt[i]]%p;
    ans = (ANS[n]-dec+p)%p;
    printf("%d",ans);
    return 0;
}
