/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
vector<int>ro[100006];
int a[100005];
int val[100005];
int in[100005];
queue<int>Q;
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1;i<=n;i++){
        for(int j = i-(i/a[i])*a[i];j<=n;j+=a[i]){
            if(a[j]>a[i]){ro[j].push_back(i);++in[i];}
        }
    }
    for(int i = 1;i<=n;i++){
        if(!in[i])Q.push(i);
    }
    while(Q.size()){
        int now = Q.front();Q.pop();
        for(int to:ro[now]){
            val[to] |= (!val[now]);
            --in[to];
            if(!in[to])Q.push(to);
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<"AB"[1-val[i]];
    }
    return 0;
}