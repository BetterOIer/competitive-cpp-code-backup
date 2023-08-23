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
#include<algorithm>
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[1000005],idx=0;
struct node{
    int x;
    int y;
};
map<int,int>m;
vector<node>team[2];
bool operator < (node a,node b){
    return a.x<b.x;
}

int main(){
    int q=read();
    for(int i = 1,opt,t,x,y,k;i<=q;i++){
        opt=read();
        if(opt&1){
            t=read(),x=read(),y=read();
            if(m.find(x)==m.end()){
                m[x]=++idx;
                x=idx;
            }else{
                x=m[x];
            }
            team[t].push_back((node){x,y});
        }else{
            k=read();
        }
        /* cope(); */
    }
    return 0;
}