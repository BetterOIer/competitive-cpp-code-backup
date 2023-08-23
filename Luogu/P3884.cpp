#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int rea[3], D, k=0;
}tree[101];
struct Qnode{
    int po,deep,dist;
};
queue <Qnode> Q;
int n,everydeep[111];
bool zg[110];
int main(){
    cin>>n;
    for(int i = 1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].rea[tree[u].k]=v,tree[u].k++;
        tree[v].rea[tree[v].k]=u,tree[v].k++;
    }
    Qnode root;
    root.po=1,root.deep=1,tree[1].D=1,zg[1]=true;
    Q.push(root);
    while(!Q.empty()){
        Qnode now=Q.front();Q.pop();
        everydeep[now.deep]++;
        for(int i = 0;i<tree[now.po].k;i++){
            if(!zg[tree[now.po].rea[i]]){
                Qnode next;
                next.deep=now.deep+1;
                next.po=tree[now.po].rea[i];
                zg[tree[now.po].rea[i]]=true;
                tree[next.po].D=next.deep;
                Q.push(next);
            }
        }
    }
    int Deepmax=0,Widemax=0;
    for(int i = 110;i>=1;i--){
        if(!Deepmax) if(everydeep[i]) Deepmax=i;
        Widemax=max(Widemax,everydeep[i]);
    }
    cout<<Deepmax<<endl<<Widemax<<endl;

    int start,end;
    memset(zg,false,sizeof(zg));
    cin>>start>>end;
    Qnode START;
    START.deep=tree[start].D, START.po=start, START.dist=0;
    zg[start]=true;
    Q.push(START);
    while(!Q.empty()){
        Qnode now=Q.front();Q.pop();
        for(int i = 0;i<tree[now.po].k;i++){
            if(now.po==end){
                cout<<now.dist<<endl;
                return 0;
            }
            if(!zg[tree[now.po].rea[i]]){
                Qnode next;
                next.po=tree[now.po].rea[i];
                next.deep=tree[tree[now.po].rea[i]].D;
                zg[tree[now.po].rea[i]]=1;
                if(next.deep<now.deep) next.dist=now.dist+2;
                else next.dist=now.dist+1;
                Q.push(next);
            }
        }
    }
}