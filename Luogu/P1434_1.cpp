#include<iostream>
#include<queue>
using namespace std;
struct node{
    int i,j,num;
};
struct cmp1{
    bool operator()(node x,node y){
        return x.num>y.num;
    }
};
priority_queue<node,vector<node>,cmp1>q;
int n,m,maxn,maxj,maxi,w,top=0,a[101][101],f[101][101];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	f[i][j]=1;
            cin>>a[i][j];
            node p;
            p.i=i;p.j=j;p.num=a[i][j];
            q.push(p);
        }
    }
    while(!q.empty()){
        node nt=q.top();
        int i=nt.i;
        int j=nt.j;
        int num=nt.num;
        q.pop();
        if(a[i-1][j]<num) f[i][j]=max(f[i][j],f[i-1][j]+1);
        if(a[i+1][j]<num) f[i][j]=max(f[i][j],f[i+1][j]+1);
        if(a[i][j-1]<num) f[i][j]=max(f[i][j],f[i][j-1]+1);
        if(a[i][j+1]<num) f[i][j]=max(f[i][j],f[i][j+1]+1);
        if(maxn<f[i][j]) maxn=f[i][j];
    }
    cout<<maxn;
    return 0;
}
