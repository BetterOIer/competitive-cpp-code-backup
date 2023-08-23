/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 1e9+7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k;
int a[10000005];
int ans=0,tot=0;
int main(){
    n=read(),k=read();
    for(int i = 1;i<=n;i++){
        a[i]=i;
    }
    do{
        bool ok=true;tot++;
        //for(int i = 1;i<=n;i++)cout<<a[i]<<" ";
        for(int i = 1;i<=n;i++){
            if(abs(a[i]-i)>k){
                ok=false;
                break;
            }
        }
        //cout<<ok<<endl;
        (ans+=ok)%=mod;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}