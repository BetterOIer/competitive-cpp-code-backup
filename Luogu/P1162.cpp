#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
int map[31][31];
int dir[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
queue <int> Q[2];
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            cin>>map[i][w];
        }
    }
    Q[0].push(1);
    Q[1].push(1);
    while(!Q[0].empty()){
        int y=Q[0].front();
        int x=Q[1].front();
        Q[0].pop();
        Q[1].pop();
        for(int i = 1;i<=4;i++){
            if(y+dir[i][0]>0&&y+dir[i][0]<=n&&x+dir[i][1]>0&&x+dir[i][1]<=n){
                if(map[y+dir[i][0]][x+dir[i][1]]==0){
                    Q.push(a[now_po.y+dir[i][0]][now_po.x+dir[i][1]]);
                    a[now_po.y+dir[i][0]][now_po.x+dir[i][1]].act=1;
                    ans++;
                }
            }
        }
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}
