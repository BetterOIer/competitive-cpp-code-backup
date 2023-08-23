#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dt[1006][1006],n,m,sty,t,stx,cnt=0;
int vis[1006][1006];
string order[1005];
struct node{
    int x;
    int y;
    int step;
};
map<string,int>M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<node>Q;
int main(){
    n=read(),m=read();
    char c;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>c;
            if(c=='.')dt[i][j]=0;
            if(c=='*')dt[i][j]=0,sty=i,stx=j;
            if(c=='X')dt[i][j]=1;
        }
    }
    t=read();
    string s;
    for(int i = 1;i<=t;i++){
        cin>>s;
        order[i]=s;
    }
    node start;
    start.step=1;
    start.y=sty;
    start.x=stx;
    M["NORTH"]=3;
    M["WEST"]=1;
    M["SOUTH"]=2;
    M["EAST"]=0;
    Q.push(start);
    while(Q.size()){
        node now = Q.front();
        Q.pop();
        if(now.step>t){
            dt[now.y][now.x]=2;
            continue;
        }
        while(vis[now.y+dy[M[order[now.step]]]][now.x+dx[M[order[now.step]]]]!=now.step+1&&now.y+dy[M[order[now.step]]]<=n&&now.y+dy[M[order[now.step]]]>0&&now.x+dx[M[order[now.step]]]<=m&&now.x+dx[M[order[now.step]]]>0&&dt[now.y+dy[M[order[now.step]]]][now.x+dx[M[order[now.step]]]]!=1){
            now.y+=dy[M[order[now.step]]];
            now.x+=dx[M[order[now.step]]];
            now.step++;
            vis[now.y][now.x]=now.step;
            Q.push(now);
            now.step--;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(dt[i][j]==0)cout<<'.';
            if(dt[i][j]==2)cout<<'*';
            if(dt[i][j]==1)cout<<'X';
        }
        cout<<"\n";
    }
}