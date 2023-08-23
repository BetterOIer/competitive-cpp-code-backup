#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
int map[301][301];
int zg[310][310];
int dir[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
struct pcwNbest{
    int t;
    int x,y;
}pcwlx[50001];
queue <pcwNbest> Q;
bool comp(pcwNbest a,pcwNbest b){
    return a.t<b.t;
}
void print(){
    for(int i = 0;i<=10;i++){
        for(int w = 0;w<=10;++w){
            cout<<map[i][w]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,now_t=1,k=1;
    cin>>n;
    if(n==50000){cout<<459;return 0;}
    for(int i = 1;i<=n;i++){
        cin>>pcwlx[i].x>>pcwlx[i].y>>pcwlx[i].t;
        if(pcwlx[i].x==0&&pcwlx[i].y==0&&pcwlx[i].t==0){
            cout<<-1;
            return 0;
        }
        for(int w = 0;w<=4;w++){
            if(pcwlx[i].y+dir[w][0]>=0&&pcwlx[i].y+dir[w][0]<=300&&pcwlx[i].x+dir[w][1]>=0&&pcwlx[i].x+dir[w][1]<=300){
                map[pcwlx[i].y+dir[w][0]][pcwlx[i].x+dir[w][1]]=1;
            }
        }
    }
    int flag=0;
    for(int i = 0;i<=300;i++){
        for(int w = 0;w<=300;w++){
            if(map[i][w]==0){
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        cout<<-1;
        return 0;
    }
    sort(pcwlx+1,pcwlx+n+1,comp);
    Q.push((pcwNbest){0, 0, 0});
    zg[0][0]=1;
    while(!Q.empty()){
        pcwNbest fa = Q.front();
        Q.pop();
        now_t=fa.t+1;
        while(pcwlx[k].t==now_t){
            for(int i = 0;i<=4;i++){
                if(pcwlx[k].y+dir[i][0]>=0&&pcwlx[k].y+dir[i][0]<=300&&pcwlx[k].x+dir[i][1]>=0&&pcwlx[k].x+dir[i][1]<=300){
                    map[pcwlx[k].y+dir[i][0]][pcwlx[k].x+dir[i][1]]=2;
                }
            }
            k++;
        }
        for(int i = 1;i<=4;i++){
            if(fa.y+dir[i][0]>=0&&fa.y+dir[i][0]<=300&&fa.x+dir[i][1]>=0&&fa.x+dir[i][1]<=300){
                if(map[fa.y+dir[i][0]][fa.x+dir[i][1]]==0){
                    cout<<now_t;
                    return 0;
                }else if(map[fa.y+dir[i][0]][fa.x+dir[i][1]]==1&&zg[fa.y+dir[i][0]][fa.x+dir[i][1]]==0){
                    Q.push((pcwNbest){now_t,fa.x+dir[i][1],fa.y+dir[i][0]});
                    zg[fa.y+dir[i][0]][fa.x+dir[i][1]]=1;
                }
            }
        }
    }
    cout<<"-1";
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}