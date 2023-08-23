#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pari;
typedef pair<int,pari> par;

int n;
int C[10][10];
stack<int> A[10][10],B[10][10];
priority_queue<par,vector<par>,less<par> > Q1;
priority_queue<par,vector<par>,greater<par> > Q2;

inline void move(int i,int j,int x,int y){
    for(;i<x;i++) printf("%d %d D 1\n",i,j);
    for(;j<y;j++) printf("%d %d R 1\n",i,j);
}

inline void Sort1(int x,int y){
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            if((i!=x||j!=y)&&!A[i][j].empty()) Q1.push(par(A[i][j].top(),pari(i,j)));
    while(!Q1.empty()){
        A[x][y].push(Q1.top().X);
        int i=Q1.top().Y.X,j=Q1.top().Y.Y; Q1.pop();
        move(i,j,x,y); A[i][j].pop();
        if(!A[i][j].empty()) Q1.push(par(A[i][j].top(),pari(i,j)));
    }
}

inline void Sort2(int x,int y){
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            if((i!=x||j!=y)&&!A[i][j].empty()) Q2.push(par(A[i][j].top(),pari(i,j)));
    while(!Q2.empty()){
        A[x][y].push(Q2.top().X);
        int i=Q2.top().Y.X,j=Q2.top().Y.Y; Q2.pop();
        move(i,j,x,y); A[i][j].pop();
        if(!A[i][j].empty()) Q2.push(par(A[i][j].top(),pari(i,j)));
    }
}

void solve(int x,int y,int wh){
    if(x==1&&y==1){
        if(!B[x][y].empty()) A[x][y].push(B[x][y].top()),B[x][y].pop();
        return ;
    }
    if((x==1&&y==2)||(x==2&&y==1)){
        if(B[1][1].empty()) return ;
        int i=B[1][1].top(); B[1][1].pop();
        if(B[1][1].empty()){ A[x][y].push(i); move(1,1,x,y); return ; }
        int j=B[1][1].top(); B[1][1].pop();
        if((i>j)^wh) printf("%d %d %c 2\n",1,1,x==1?'R':'D');
        else printf("%d %d %c 1\n%d %d %c 1\n",1,1,x==1?'R':'D',1,1,x==1?'R':'D');
        if(wh) A[x][y].push(max(i,j)),A[x][y].push(min(i,j));
        else A[x][y].push(min(i,j)),A[x][y].push(max(i,j));
        return ;
    }
    for(int i=x;i;i--)
        for(int j=y;j;j--)
            if(i!=x||j!=y) solve(i,j,wh^1);
    if(wh) Sort1(x,y);
    else Sort2(x,y);
}

int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x); B[1][1].push(x);
    }
    solve(6,6,1);
}
