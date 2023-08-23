#include<bits/stdc++.h>
using namespace std;
struct node{
    int L,R,F,A,C;
    bool vis=false;
}tree[1000006];
queue <int> Q;
int qi[1000006],ho[1000006],k1=1,k2=1,ans=0;
void qian(int root){
    if(tree[root].L){
        qian(tree[root].L);
    }
    qi[k1++]=tree[root].C;
    if(tree[root].R){
        qian(tree[root].R);
    }
}
void hou(int root){
    if(tree[root].R){
        hou(tree[root].R);
    }
    ho[k2++]=tree[root].C;
    if(tree[root].L){
        hou(tree[root].L);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>tree[i].C;
    }
    for(int i =1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x!=-1){
            tree[i].L=x;
            tree[x].F=i;
        }
        if(y!=-1){
            tree[i].R=y;
            tree[y].F=i;
        }
        if(x==-1&&y==-1)Q.push(i);
    }
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        tree[tree[now].F].A+=tree[now].A+1;
        if(!tree[tree[now].F].vis){
            Q.push(tree[now].F);
            tree[tree[now].F].vis=true;
        }
    }
    Q.push(1);
    while(!Q.empty()){
        int i = Q.front();Q.pop();
        if(tree[i].A%2){
            if(tree[i].L)Q.push(tree[i].L);
            if(tree[i].R)Q.push(tree[i].R);
        }else{
            memset(qi,0,sizeof(qi));
            memset(ho,0,sizeof(ho));
            k1=k2=1;
            qian(i),hou(i);
            bool flag=true;
            for(int i = 1;i<=k1;i++){
                if(qi[i]!=ho[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans=max(tree[i].A+1,ans);
            }else{
                if(tree[i].L)Q.push(tree[i].L);
                if(tree[i].R)Q.push(tree[i].R);
            }
        }
    }
    cout<<ans;
}