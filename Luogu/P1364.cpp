#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,vis[110];
long long DIST=100000000000000000,dist;
struct node1{
    int po;
    int dis;
};
queue <node1> Q;
struct node{
    int data;
    int oth[4];
}a[110];
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].data>>a[i].oth[2]>>a[i].oth[3];
        if(a[i].oth[2])a[a[i].oth[2]].oth[1]=i;
        if(a[i].oth[3])a[a[i].oth[3]].oth[1]=i;
    }
    for(int i = 1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dist=0;
        Q.push((node1){i,1});
        vis[i]=1;
        while(!Q.empty()){
            node1 now=Q.front();
            Q.pop();
            for(int j = 1;j<=3;j++){
                if(vis[a[now.po].oth[j]]==0&&a[now.po].oth[j]){
                    dist=dist+a[a[now.po].oth[j]].data*now.dis;
                    vis[a[now.po].oth[j]]=1;
                    Q.push((node1){a[now.po].oth[j],now.dis+1});
                }
            }
        }
        DIST=min(DIST,dist);
    }
    cout<<DIST;
}