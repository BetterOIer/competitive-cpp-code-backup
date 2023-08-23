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
long long n,p;
long long t;
int main(){
    t=read();
    while(t--){
        n=read(),p=read();
        if(p==1||p>2*n){
            for(int i = 1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }else if(p&1){
            long long cnt=p/2;
            for(long long i = 1;i<=cnt;i++){
                for(long long j = i,w = p-i;j<=n;j+=p,w+=p){
                    printf("%lld ",j);
                    if(w<=n)printf("%lld ",w);
                }
            }
            for(long long i = p;i<=n;i+=p){
                printf("%lld ",i);
            }
        }else{
            long long cnt=p/2-1;
            for(long long i = 1;i<=cnt;i++){
                for(long long j = i,w = p-i;j<=n;j+=p,w+=p){
                    printf("%lld ",j);
                    if(w<=n)printf("%lld ",w);
                }
            }
            for(long long i = cnt+1;i<=n;i+=p){
                printf("%lld ",i);
            }
            for(long long i = p;i<=n;i+=p){
                printf("%lld ",i);
            }
        }
        printf("\n");
    }
    return 0;
}