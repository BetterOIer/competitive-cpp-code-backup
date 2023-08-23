#include<bits/stdc++.h>
using namespace std;
int ctrl[21],vis[1001];
long long ANS=9223372036854775807;
struct node{
    int floor;
    int ctdir;
    int tim;
};
queue <node> Q;
int main(){
    bool flag=false;
    int n,m,I;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>ctrl[i];
        if(ctrl[i]==0) I=i;
    }
    node fir;
    fir.floor=1,fir.ctdir=I,fir.tim=0;
    Q.push(fir);
    while(!Q.empty()){
        node now=Q.front(),next;Q.pop();
        if(now.floor==n){
            ANS=ANS<now.tim? ANS:now.tim;
            flag=1;
            continue;
        }
        for(int i = 1;i<=m;i++){
            if(now.floor+ctrl[i]>=1&&now.floor+ctrl[i]<=n&&(!vis[now.floor+ctrl[i]])&&now.tim<ANS){
                next.ctdir=i;
                next.floor=now.floor+ctrl[i];
                next.tim=now.tim+abs(ctrl[i])*2+abs(now.ctdir-next.ctdir);
                vis[now.floor+ctrl[i]]=true;
                Q.push(next);
            }
        }
    }
    if(!flag) cout<<-1;
    else cout<<ANS;
}