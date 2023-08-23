#include<iostream>
using namespace std;
unsigned long long qp[25][25];
int dir[9][2]={{0,0},{-1,-2},{-2,-1},{-2,+1},{-1,+2},{+1,-2},{+2,-1},{+2,+1},{+1,+2}};
int main(){
    int n,m,x,y,flag = 0;
    cin>>n>>m>>x>>y;
    for(int i = 0;i<=8;i++){
        dir[i][0]+=(x+2);
        dir[i][1]+=(y+2);
    }
    for(int  i= 0;i<=n&&flag == 0;i++){
        qp[i+2][0+2]=1;
        for(int j = 0;j<=8&&flag==0;j++){
            if(dir[j][0]==i+2&&dir[j][1]==0+2){
                qp[i+2][0+2]=0;
                flag = 1;
            }
        }
    }
    flag = 0;
    for(int  i= 0;i<=m&&flag == 0;i++){
        qp[0+2][i+2]=1;
        for(int j = 0;j<=8&&flag==0;j++){
            if(dir[j][0]==0+2&&dir[j][1]==i+2){
                qp[0+2][i+2]=0;
                flag = 1;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=m;w++){
            qp[i+2][w+2]= qp[i-1+2][w+2]+qp[i+2][w-1+2];
            for(int j = 0;j<=8;j++){
                if(i+2==dir[j][0]&&w+2==dir[j][1]){
                    qp[i+2][w+2]=0;
                    break;
                }
            }
        }
    }
    cout<<qp[n+2][m+2];
    return 0;
} 