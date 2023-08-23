#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int x,y,n;
};
struct comp{
    bool operator()(node x,node y){
        return x.n>y.n;
    }
};
priority_queue<node,vector<node>,comp>q;
int a[101][101],b[101][101],ans=0;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=m;w++){
            cin>>a[i][w];
            node p;
            p.n=a[i][w],p.x=w,p.y=i;
            q.push(p);
            b[i][w]=1;
        }
    }
    while(!q.empty()){
        node nt=q.top();
        int x=nt.x;
        int y=nt.y;
        int num=nt.n;
        q.pop();
        for(int j = 0;j<=3;j++){
            if(a[y+dir[j][0]][x+dir[j][1]]<num){
                b[y][x]=max(b[y][x],b[y+dir[j][0]][x+dir[j][1]]+1);
                ans=max(ans,b[y][x]);
            }
        }
    }
    cout<<ans;
    return 0;
}