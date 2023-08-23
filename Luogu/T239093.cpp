#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
//#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
int map[11][11],ycw,xcw,ky,kx,n,m,t,f=0,home_n=0;
int dir[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int tn){
    int flag=0;
    if(map[ycw][xcw]==3&&home_n==0){
        f=1;
    }
    for(int i = 1;i<=4;i++){
        if(ycw+dir[i][0]>0&&ycw+dir[i][0]<=n&&xcw+dir[i][1]>0&&xcw+dir[i][1]<=m&&map[ycw+dir[i][0]][xcw+dir[i][1]]!=1&&tn+1<=t){
            ky = ycw,kx = xcw;
            ycw=ycw+dir[i][0],xcw=xcw+dir[i][1];
            if(map[ycw][xcw]==2){
                home_n--;
                map[ycw][xcw]==0;
                flag=1;
            }
            dfs(tn+1);
            if(flag){
                home_n++;
                map[ycw][xcw]==2;
                flag=0;
            }
            ycw = ky,xcw=kx;
        }
    }
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,m,t;
    cin>>n>>m>>t;
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=m;w++){
            char c;
            cin>>c;
            if(c=='@'){
                ycw=i,xcw=w;
                map[i][w]=0;
            }else if(c=='.')map[i][w]=0;
            else if(c=='$')map[i][w]=2,home_n++;
            else if(c=='*')map[i][w]=1;
            else if(c=='#')map[i][w]=3;
        }
    }
    dfs(0);
    if(f==0){
        cout<<"SINB PCW!!!";
    }else if(f==1){
        cout<<"PCW NB!!!";
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}
