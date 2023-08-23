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
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int life[100005],recov[100005],reward[100005],pre[1000005];
int exgcd(int a,int b,int &x,int &y){
    if(b==0) return x=1,y=0,a;
    int d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
multiset<int>sword;

int CRT(int r[], int m[]){
    int M=1, ans=0;
    for(int i =1;i<=n;i++) M*=m[i];
    for(int i = 1;i<=n;i++){
        int c=M/m[i],x,y;
        exgcd(c,m[i],x,y);
        (ans+=(r[i]*c*x%M))%=M;
    }
    return (ans%M+M)%M;
}
int main(){
    int t=read();
    while(t--){
        n=read(),m=read();
        for(int i = 1;i<=n;i++) life[i]=read();
        for(int i = 1;i<=n;i++) recov[i]=read();
        for(int i = 1;i<=n;i++) reward[i]=read();
        for(int i = 1,atk;i<=m;i++)atk=read(),sword.insert(atk);
        sort(sword.begin(),sword.end());
        for(int i = 1,x,y;i<=n;i++){
            vector<int>::iterator choice=upper_bound(sword.begin(),sword.end(),life[i]);
            if(choice!=sword.begin())--choice;
            int gcd=exgcd(*choice,recov[i],x,y);
            pre[i] = *choice, sword.erase(choice), sword.insert(reward[i]);
			mx = max(mx, (a[i]-1)/b[i]+1);
        }
    }
    return 0;
}