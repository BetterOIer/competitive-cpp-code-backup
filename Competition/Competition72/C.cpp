/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<set>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int a[1000005];
int tmp[1000005],idx=0;
set<int>s;
void get_fib(){
    s.clear();
    int x=1,y=1,z=0;
    while(x<=2e9){
        s.insert(x);
        z=y;
        y=x;
        x=y+z;
    }
}
int main(){
    freopen("f.in","r",stdin);
    freopen("f.out","w",stdout);
    get_fib();
    n=read();
    int ans=1;
    for(int i = 1;i<=n;i++) a[i]=read();
    tmp[++idx]=a[1];
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=idx;j++){
            if(s.find(a[i]+tmp[j])!=s.end()){
                ans++,idx=0;
                break;
            }
        }
        tmp[++idx]=a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}