#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int t,l,r;
int main(){
    t=read();
    while(t--){
        l=read(),r=read();
        if(r-l>=10)printf("%d\n",0);
        else {
            long long ans=1;
            for(int i=l;i<=r;i++){
                int x=i;
                while(x){
                    ans*=x%10;
                    x/=10;
                    ans%=1000000007;
                }
                
            }
            printf("%d\n",ans);
        }
    }
}