#include<iostream>
#include<cstring>
using namespace std;
int chess[401][401],m,n;
int dire[8][2] = {{-1,-2},{-2,-1},{-2,+1},{-1,+2},{+1,+2},{+2,+1},{+2,-1},{+1,-2}};
void dfs(int x,int y){
    for(int i = 0;i<=7;i++){
        int x1 = x+dire[i][1],y1 = y+dire[i][0];
        if(y1>0&&y1<=m&&x1>0&&x1<=n){
            if(chess[y1][x1]>=chess[y][x]+1){
                int k = chess[y1][x1];
                chess[y1][x1] = chess[y][x]+1;
                dfs(x1,y1);
                //chess[y1][x1] = k;
            }
        }
    }
}
void print(){
    for(int i = 1;i<=m;i++){
        for(int w = 1;w<=n;w++){
            if(chess[i][w]==1000000)printf("-1   ");
            else printf("%-5d", chess[i][w]);
        }
        printf("\n");
    }
}
int main(){
    //freopen("P1443.in","r",stdin);
    //freopen("P.out","w",stdout);
    int x,y;
    cin>>m>>n>>y>>x;
    for(int i = 1;i<=m;i++)for(int w = 1;w<=n;w++)chess[i][w]=1000000;
    chess[y][x]=0;
    dfs(x,y);
    print();
    //fclose(stdin);
    //fclose(stdout);
    return 0;
} 