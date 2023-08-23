#include<iostream>
using namespace std;
struct zm{
    int num;
    int used=0;
}a[101][101];
int flag=0,n;
int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
void dfs(int y,int x,int num,int i){
    if(num==7){
        flag=1;
    }
    if(a[y+dir[i][0]][x+dir[i][1]].num==num+1){
        dfs(y+dir[i][0],x+dir[i][1],num+1,i);
        if(flag==1){
            a[y+dir[i][0]][x+dir[i][1]].used=1;
        }
    }
}
int main(){
    int k=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            char c;
            cin>>c;
            if(c=='y')a[i][w].num=1;
            else if(c=='i')a[i][w].num=2;
            else if(c=='z')a[i][w].num=3;
            else if(c=='h')a[i][w].num=4;
            else if(c=='o')a[i][w].num=5;
            else if(c=='n')a[i][w].num=6;
            else if(c=='g')a[i][w].num=7;
            else a[i][w].num=0;
        }
    }
    
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            if(a[i][w].num==1){
                for(int j=0;j<=7;j++){
                    dfs(i,w,1,j);
                    if(flag==1){
                        a[i][w].used=1;
                        flag=0;
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            if(a[i][w].used==0)cout<<"*";
            else {
                if(a[i][w].num==1)cout<<'y';
                else if(a[i][w].num==2)cout<<'i';
                else if(a[i][w].num==3)cout<<'z';
                else if(a[i][w].num==4)cout<<'h';
                else if(a[i][w].num==5)cout<<'o';
                else if(a[i][w].num==6)cout<<'n';
                else if(a[i][w].num==7)cout<<'g';
            }
        }
        cout<<endl;
    }
    return 0;
}