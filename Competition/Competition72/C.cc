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
int n,ans=1;
int fib[50]={1,2},idx=1;
int a[100005];
void get_fib(){
    while(fib[idx]<1836311903){
        idx++;
        fib[idx]=fib[idx-1]+fib[idx-2];
    }
}
set<int>s;
int main(){
    freopen("f.in","r",stdin);
    freopen("f.out","w",stdout);
    get_fib();
    n=read();
    for(int i = 1,x;i<=n;i++){
        x=read();
        for(int j = idx;j>=0;j--){
            if(s.find(fib[j]-x)!=s.end()){
                ans++;
                s.clear();
            }
        }
        s.insert(x);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}