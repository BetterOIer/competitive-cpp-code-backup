#include<bits/stdc++.h>
using namespace std;
struct node{
    int L,R,F,A,C;
    bool vis=false;
}tree[105];
queue <int> Q;
void deal(int root){
    if(tree[root].A%2){
        deal(tree[root].L);
        deal(tree[root].R);
    }else{
        cout<<tree[root].A;
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
    deal(1);
}