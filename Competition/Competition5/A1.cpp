#include<bits/stdc++.h> //万能头 
using namespace std;
char a[22][22];  //存障碍物的数组 
bool p[22][22];  //存有没有走过,走过是1，没走过是0 
int n,m,t,sx,sy,dx,dy;
bool pdd=0; //判断是否输出yes 
int fx[4]={0,0,1,-1}; //方向，弄成两个比较好对照 
int fy[4]={-1,1,0,0};
void dfs(int x,int y,int tt){//tt是时间 
    if(x==dx&&y==dy){
        if(tt==t)pdd=1;  //如果可以就设为1 
        return;//碰到终点就返回 
    }
    if(tt>=t)return;//如果时间超了也直接返回，可以省非常多时间 
    for(int i=0;i<=3;i++){
        int xx=x+fx[i],yy=y+fy[i];
        if(xx>0&&yy>0&&yy<=n&&xx<=m){
        if(p[yy][xx]==0&&a[yy][xx]!='X'){
            p[yy][xx]=1;   //正常深搜 
            dfs(xx,yy,tt+1);
            p[yy][xx]=0;
        }
        }
    }
}
int main(){
    while(cin>>n>>m>>t){
        if(n==0&&m==0&&t==0)break;//结束条件 
        memset(p,0,sizeof(p));//一定要重置！！！ 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S'){//起始位置存一下 
                    sx=j;
                    sy=i;
                    p[i][j]=1;  //把开始位置设置成1，不能再走了 
                }
                else if(a[i][j]=='D'){
                    dx=j;
                    dy=i;
                }
            }
        }
        dfs(sx,sy,0);//从起点开始搜，0代表时间 
        if(pdd==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        pdd=0;//非常重要的清零 
    }
    return 0;//圆满结束，是不是通俗易懂 
} 