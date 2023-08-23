#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int map[21][21],x,y,t,y11,x11,x22,y22,flag = 0;
int dir[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int t1){
    if(y11>=1&&y11<=y&&x11>=1&&x11<=x&&flag==0){
        if(map[y11][x11]==0&&t1-1<=t){
            map[y11][x11]=1;
            for(int i = 1;i<=4&&flag ==0;i++){
                int ky = y11,kx = x11;
                y11 = y11+dir[i][0],x11 =x11+dir[i][1];
                dfs(t1+1);
                y11=ky,x11=kx;
            }
            map[y11][x11]=0;
        }else if(map[y11][x11]==1){
            return;
        }else if(map[y11][x11]==2&&t1==t){
            flag=1;
        }
    } 
}
int main(){
    while(true){
        memset(map,0,sizeof(map));
        flag = 0;
        cin>>y>>x>>t;
        if(x==0&&y==0&&t==0){
            break;
        }
        for(int i = 1;i<=y;i++){
            for(int w = 1;w<=x;w++){
                char a;
                cin>>a;
                if(a=='.')map[i][w]=0;
                else if(a=='X')map[i][w]=1;
                else if(a=='S')x11 = w,y11 = i;
                else map[i][w]=2,x22=w,y22=i;
            }
        }
        if(abs(x22-x11)+abs(y22-y11)>t){
            cout<<"NO"<<endl;
            continue;
        }
        dfs(0);
        if(flag==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}