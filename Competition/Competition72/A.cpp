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
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int a[100005],tmp[100005];
bool check(int l1,int r1,int sta,int l){
    for(int i = sta;i<sta+l;i++){
        tmp[i-sta]=a[i];
    }
    nth_element(tmp,tmp+((l-1)>>1),tmp+l);
    return tmp[(l-1)>>1]<=r1&&tmp[(l-1)>>1]>=l1;
}
int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    m=read();
    for(int i = 1,l1,r1,l2,r2,ans;i<=m;i++){
        l1=read(),r1=read(),l2=read(),r2=read(),ans=0;
        for(int l = l2;l<=r2;l++){
            for(int sta = 1;sta<=n-l+1;sta++){
                if(check(l1,r1,sta,l)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}